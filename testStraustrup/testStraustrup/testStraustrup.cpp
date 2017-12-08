// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>     // std::string, std::stoi
#include <vector>  
using namespace std;

auto _colMax(vector<double> *col) {
	auto max = (*col)[0];
	for (auto temp : *col) {
		if (temp > max)
			max = temp;
	}
	return max;
}
auto _colMin(vector<double> *col) {
	auto min = (*col)[0];
	for (auto temp : *col) {
		if (temp < min)
			min = temp;
	}
	return min;
}

int main() {
	vector<double> vc;
	string temp;
	while (true) {
		cin >> temp;
		if (temp == "|")
			break;
		vc.push_back(stod(temp));
	}
	double maxVecNum = _colMax(&vc);
	double minVecNum = _colMin(&vc);

	if (maxVecNum == minVecNum)
		cout << "Numbers are equal = " << maxVecNum << endl;
	else if (abs(maxVecNum - minVecNum) > 1.0 && abs(maxVecNum - minVecNum) < 100)
		cout << "Numbers are almost equal " << endl;
	else {
		cout << "Max value = " << maxVecNum << endl;
		cout << "Min value = " << minVecNum << endl;
	}
	cin >> temp;		//pause
	return 0;
}

