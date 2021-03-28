#include <iostream>
#include "MapCollection.h"

using namespace std;

int main()
{
	MapCollection mapCollection;
	

	while (true) {
		mapCollection.Print();
		mapCollection.PrintOriginal();
		char direction;
		cin >> direction;
		if(direction == 'd')
			mapCollection.D();
		if (direction == 'a')
			mapCollection.A();
		if (direction == 'w')
			mapCollection.W();
		if (direction == 's')
			mapCollection.S();


	}
	
}

