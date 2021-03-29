#pragma once

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class MapCollection2 {

	int chunkX = 4, chunkZ = 4;
	int chunkY = 64;

	int range = 2;

	int playerX = 50, playerZ = 50;

	deque<deque<vector<char>>> map;
	string worldName = "world1";

public:

	MapCollection2() {
		LoadMap();
	}

	void Print() {
		system("cls");
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map.at(i).size(); j++) {
				cout << map.at(i).at(j)[0] << " ";
			}
			cout << endl;
		}
	}

	void W() {
		for (int i = 0; i < chunkZ; i++) {
			map.pop_front();
			deque<vector<char>> row((2 * range + 1) * chunkX, vector<char>((2 * range + 1) * chunkY, '1'));
			map.push_back(row);
		}

		playerZ--;
	}

	void A() {

		//Dla ka¿dego chunka...
		for (int i = 0; i < (2 * range + 1); i++) {
			//Dla ka¿dego wiersza w chunku...
			for (int j = 0; j < chunkZ; j++) {
				//Dla ka¿dego filaru w wierszu...
				for (int k = 0; k < chunkX; k++) {
					//Zapisz pilar do pliku.
					map.at(i * chunkZ + j).back();
					//Usuñ pilar.
					map.at(i * chunkZ + j).pop_back();
					//Wczytaj/wygeneruj nowy pilar.
					map.at(i * chunkZ + j).push_front(vector<char>(chunkY, '1')); //Wczytaj.
				}
			}
		}

		playerX--;
	}

	void S() {
		for (int i = 0; i < chunkZ; i++) {
			map.pop_back();
			deque<vector<char>> row((2 * range + 1) * chunkX, vector<char>((2 * range + 1) * chunkY, '1'));
			map.push_front(row);
		}

		playerZ++;
	}

	void D() {
		//Dla ka¿dego chunka...
		for (int i = 0; i < (2 * range + 1); i++) {
			//Dla ka¿dego wiersza w chunku...
			for (int j = 0; j < chunkZ; j++) {
				//Dla ka¿dego filaru w wierszu...
				for (int k = 0; k < chunkX; k++) {
					//Zapisz pilar do pliku.
					map.at(i * chunkZ + j).front();
					//Usuñ pilar.
					map.at(i * chunkZ + j).pop_front();
					//Wczytaj/wygeneruj nowy pilar.
					map.at(i * chunkZ + j).push_back(vector<char>(chunkY, '1')); //Wczytaj.
				}
			}
		}

		playerX++;
	}

	void LoadMap() {

		for (int i = 0; i < 2 * range + 1; i++) {
			for (int j = 0; j < chunkZ; j++) {
				deque<vector<char>> row((2 * range + 1) * chunkX, vector<char> ((2 * range + 1) * chunkY, '0'));
				map.push_back(row);
			}
		}

	}
};
