// difibrilator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/

double _strReplace(string item) {
	string res;
	for (int i = 0; i < item.length(); i++)
		if (item[i] != ',')
			res += item[i];
		else
			res += '.';

	return stod(res);
}

void getInitialData(double &longtitude, double &latitude, int &numberOfItems) {
	string tempLat, tempLong;
	cin >> tempLong; cin.ignore();
	cin >> tempLat; cin.ignore();
	cin >> numberOfItems; cin.ignore();

	longtitude = _strReplace(tempLong);
	latitude = _strReplace(tempLat);
}

string* getDifibrilatorsData(int numberOfItems) {
	string* res = new string[numberOfItems];
	for (int i = 0; i < numberOfItems; i++) 
		getline(cin, res[i]);
	return res;
}


void parseDefibrilatorData(string item, string &nameOfItem, double &latitude, double &longtitude) {
	vector<string> itemData;
	string tempItem = "";
	for (int i = 0; i < item.length(); i++) {
		if (item[i] != ';')
			tempItem += item[i];
		else {
			itemData.push_back(tempItem);
			tempItem = "";
		}
	}
	itemData.push_back(tempItem);
	nameOfItem = itemData[1];
	longtitude = _strReplace(itemData[4]);
	latitude = _strReplace(itemData[5]);
}



string serarchNearestDefibrilator(string* defibrilatorsData, int numberOfLocations, double userLongtitude, double userLatitude) {
	double nearestDist = 999999999999;
	string nearestDistName = "";
	for (int i = 0; i < numberOfLocations; i++) {
		string name;
		double lat, lon, tempX, tempY, tempDist;
		parseDefibrilatorData(defibrilatorsData[i], name, lat, lon);
		tempX = (lon - userLongtitude) * cos((userLatitude - lat) / 2);
		tempY = (lat - userLatitude);
		tempDist = sqrt(pow(tempX, 2) + pow(tempY, 2)) * 6371;
		if (nearestDist > tempDist) {
			nearestDist = tempDist;
			nearestDistName = name;
		}
	}
	return nearestDistName;
}




int main() {
	double userLongtitude, userLatitude;
	int numberOfItems;
	getInitialData(userLongtitude, userLatitude, numberOfItems);
	string* defibrilatorsData = getDifibrilatorsData(numberOfItems);
	string res = serarchNearestDefibrilator(defibrilatorsData, numberOfItems, userLongtitude, userLatitude);
	cout << res << endl;

	char testsd;
	cin >> testsd;
}