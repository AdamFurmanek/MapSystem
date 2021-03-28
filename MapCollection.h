#pragma once

#include <deque>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MapCollection {
	char testMap[300][300];

	int playerX = 50, playerY = 50;
	int range = 5;
	deque<deque<char>> map;
	deque<char> row;

public:

	MapCollection() {
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 300; j++) {
				testMap[i][j] = rand() % 3 + 46;
			}
		}

		for (int i = playerY - range; i < playerY + range + 1; i++) {
			map.push_back(row);
			for (int j = playerX - range; j < playerX + range + 1; j++) {
				map.back().push_back(testMap[i][j]);
			}
		}
	}

	void Print() {
		system("cls");
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map.at(i).size(); j++) {
				cout << map.at(i).at(j) << " ";
			}
			cout << endl;
		}
	}

	void PrintOriginal() {
		cout << endl << endl;
		for (int i = playerY - range; i < playerY + range + 1; i++) {
			for (int j = playerX - range; j < playerX + range + 1; j++) {
				cout << testMap[i][j] << " ";
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

	char GetChunk(int i, int j) {
		string path = to_string(i) + "-" + to_string(j) + ".txt";
		ifstream file;
		file.open(path);
		char c;
		if (file) {
			for (string line; getline(file, line); )
			{
				c = line[0];
			}

			file.close();
			return c;
		}
		else {
			file.close();
			//wygeneruj na podstawie seeda.
			//return rand() % 3 + 46;
			return 'a';
		}
	}

	void SaveChunk(int i, int j, char c) {
		string path = to_string(i) + "-" + to_string(j) + ".txt";
		ofstream file;
		file.open(path);
		file << c;
		file.close();
	}
	
};