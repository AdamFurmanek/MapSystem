#pragma once

#include <deque>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class MapCollection {

	int chunkX = 16, chunkY = 64, chunkZ = 16;

	int playerX = 50, playerY = 50;
	int range = 2;
	deque<deque<vector<vector<vector<char>>>>> map;
	deque<vector<vector<vector<char>>>> row;
	string worldName = "world1";

public:

	MapCollection() {
		srand(40);
		GetChunks();
	}

	void Print() {
		system("cls");
		//Aktualnie wyœwietla 4 spoœród 16384 lementów chunka.
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map.at(i).size(); j++) {
				cout << map.at(i).at(j)[0][0][0] << " " << map.at(i).at(j)[1][0][0] << " ";
			}
			cout << endl;
			for (int j = 0; j < map.at(i).size(); j++) {
				cout << map.at(i).at(j)[2][0][0] << " " << map.at(i).at(j)[3][0][0] << " ";
			}
			cout << endl;
		}
	}

	void D() {
		playerX++;
		for (int i = 0; i < map.size(); i++) {
			SaveChunk(playerY - range + i, playerX - range - 1, map.at(i).front());
			map.at(i).pop_front();
			map.at(i).push_back(GetChunk(playerY - range + i, playerX + range));
		}
	}

	void A() {
		playerX--;
		for (int i = 0; i < map.size(); i++) {
			SaveChunk(playerY - range + i, playerX + range + 1, map.at(i).back());
			map.at(i).pop_back();
			map.at(i).push_front(GetChunk(playerY - range + i,playerX - range));
		}
	}

	void W() {
		int j = map.back().size();
		for (int i = 0; i < j; i++) {
			SaveChunk(playerY + range, playerX - range + i, map.back().front());
			map.back().pop_front();
		}

		playerY--;

		map.pop_back();
		map.push_front(row);
		for (int j = playerX - range; j < playerX + range + 1; j++) {
			map.front().push_back(GetChunk(playerY - range, j));
		}
	}

	void S() {
		int j = map.front().size();
		for (int i = 0; i < j; i++) {
			SaveChunk(playerY - range, playerX - range + i, map.front().front());
			map.front().pop_front();
		}

		playerY++;

		map.pop_front();
		map.push_back(row);
		for (int j = playerX - range; j < playerX + range + 1; j++) {
			map.back().push_back(GetChunk(playerY + range,j));
		}
	}

	vector<vector<vector<char>>> GetChunk(int i, int j) {

		string path = worldName + "/" + to_string(i) + "-" + to_string(j) + ".txt";
		ifstream file;
		file.open(path);
			vector<vector<vector<char> > > chunk;
			for (int x = 0; x < chunkX; x++) {
				vector<vector<char>> sliceChunk;
				chunk.push_back(sliceChunk);
				for (int y = 0; y < chunkY; y++) {
					vector<char> sliceChunk2;
					chunk[x].push_back(sliceChunk2);
					for (int z = 0; z < chunkZ; z++) {
						char c;
						if (file) {
							file >> c;
						}
						else {
							//GENERATOR
							c = rand() % 3 + 46;
						}
						chunk[x][y].push_back(c);
					}
				}
			}

			file.close();
			return chunk;
	}

	void SaveChunk(int i, int j, vector<vector<vector<char>>> chunk) {
		string path = worldName + "/" + to_string(i) + "-" + to_string(j) + ".txt";
		ofstream file;
		file.open(path);
		for (int x = 0; x < chunkX; x++) {
			for (int y = 0; y < chunkY; y++) {
				for (int z = 0; z < chunkZ; z++) {
					file << chunk[x][y][z];
				}
			}
		}
		file.close();
	}

	void GetChunks() {
		for (int i = playerY - range; i < playerY + range + 1; i++) {
			map.push_back(row);
			for (int j = playerX - range; j < playerX + range + 1; j++) {
				map.back().push_back(GetChunk(i,j));
			}
		}
	}

	void SaveChunks() {
		for (int i = playerY - range; i < playerY + range + 1; i++) {
			for (int j = playerX - range; j < playerX + range + 1; j++) {
				SaveChunk(i, j, map.front().front());
				map.front().pop_front();
			}
			map.pop_front();
		}
	}

	void ChangeRange(int delta) {
		SaveChunks();
		range += delta;
		GetChunks();
	}
	
};