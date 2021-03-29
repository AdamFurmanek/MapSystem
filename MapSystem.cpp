#include <iostream>
#include "MapCollection2.h"

using namespace std;

#include <conio.h>

int main()
{
	MapCollection2 mapCollection;

	while (true) {
		mapCollection.Print();
		char key;
		key = _getch();
		if (key == 'w')
			mapCollection.W();
		if (key == 'a')
			mapCollection.A();
		if (key == 's')
			mapCollection.S();
		if(key == 'd')
			mapCollection.D();
		//if (key == '1')
		//	mapCollection.ChangeRange(-1);
		//if (key == '2')
		//	mapCollection.ChangeRange(1);
		//if (key == 'q') {
		//	mapCollection.SaveChunks();
		//	break;
		//}
	}
	
}

