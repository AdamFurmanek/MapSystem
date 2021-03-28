#include <iostream>
#include "MapCollection.h"

using namespace std;

int main()
{
	MapCollection mapCollection;
	
	while (true) {
		mapCollection.Print();
		char key;
		cin >> key;
		if(key == 'd')
			mapCollection.D();
		if (key == 'a')
			mapCollection.A();
		if (key == 'w')
			mapCollection.W();
		if (key == 's')
			mapCollection.S();
		if (key == '1')
			mapCollection.ChangeRange(-1);
		if (key == '2')
			mapCollection.ChangeRange(1);
		if (key == 'q') {
			mapCollection.SaveChunks();
			break;
		}
	}
}

