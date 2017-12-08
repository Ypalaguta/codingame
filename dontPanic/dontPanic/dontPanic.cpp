#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class roboClass {
public:
	int nbFloors; // number of floors
	int width; // width of the area
	int nbRounds; // maximum number of rounds
	int exitFloor; // floor on which the exit is found
	int exitPos; // position of the exit on its floor
	int nbTotalClones; // number of generated clones
	int nbAdditionalElevators; // ignore (always zero)
	int nbElevators; // number of elevators

					 //dynamic data
	int cloneFloor; // floor of the leading clone
	int clonePos; // position of the leading clone on its floor
	string direction; // direction of the leading clone: LEFT or RIGHT

	map<int, int> elevators;
	//temp data
	int clonPrevPos;
	int prevCloneFloor = 0;
	roboClass() {
		cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
		for (int i = 0; i < nbElevators; i++) {
			int elevatorFloor; // floor on which this elevator is found
			int elevatorPos; // position of the elevator on its floor
			cin >> elevatorFloor >> elevatorPos; cin.ignore();
			elevators.insert(pair<int, int>(elevatorFloor, elevatorPos));
		}
	}
	void getDynamicData() {
		cin >> cloneFloor >> clonePos >> direction; cin.ignore();
	}
	string decideWhereToGo() {
		getDynamicData();
		// cerr<<cloneFloor<<" "<<exitFloor;
		if (cloneFloor == exitFloor) {
			cerr << "exitFloor " << exitFloor << " clonePos " << clonePos << endl;
			if (direction == getDir(exitPos))
				return "WAIT";
			else
				return "BLOCK";
		}
		else {
			cerr << "elevatorPos " << elevators[cloneFloor] << " clonePos " << clonePos << endl;
			if (direction == getDir(elevators[cloneFloor]))
				return "WAIT";
			else
				return "BLOCK";
		}
	}
	string getDir(int coord) {
		cerr << "cloneFloor " << cloneFloor << " coord before " << coord << endl;
		if (coord != clonPrevPos && prevCloneFloor == cloneFloor) coord += coord < clonPrevPos ? -1 : 1;
		clonPrevPos = clonePos;
		prevCloneFloor = cloneFloor;
		cerr << "coord after " << coord << endl;
		return (coord < clonePos) ? "LEFT" : "RIGHT";
	}

};

int main() {
	roboClass roboController = roboClass();
	while (1) {
		cout << roboController.decideWhereToGo() << endl; // action: WAIT or BLOCK
	}
}