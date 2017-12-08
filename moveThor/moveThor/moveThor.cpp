#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
* ---
* Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
**/
string _moveThor(int &thorX, int &thorY, int lightX, int ligntY) {
	string pos = "";
	
	if (thorY - ligntY > 0) {
		pos += "N";
		thorY--;
	}
	else if (thorY - ligntY < 0) {
		pos += "S";
		thorY++;
	}

	if (thorX - lightX > 0) {
		pos += "W";
		thorX--;
	}
	else if (thorX - lightX < 0) {
		pos += "E";
		thorX++;
	}

	return pos;
}

void getInitialData(int &lightX, int &lightY, int &initialTX, int &initialTY) {
	cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
}

int getRemainTurns() {
	int remainTurns;
	cin >> remainTurns; cin.ignore();
	return remainTurns;
}

int main() {
	int lightX, lightY, initialTX, initialTY; 
	getInitialData(lightX, lightY, initialTX, initialTY);


	while (1) {
		int remainingTurns = getRemainTurns(); 
		cout << _moveThor(initialTX, initialTY, lightX, lightY) << endl;
	}
}