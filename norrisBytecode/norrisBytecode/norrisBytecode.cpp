// norrisBytecode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/

void lastByteAppend(char &lastByte, char currentByte, string &temp) {
	lastByte = currentByte;
	if (lastByte == '1')
		temp = "0 0";
	else
		temp = "00 0";
}

string _getNorrisCode(string bytecode) {
	string res = "";
	string temp = "";
	char lastByte;
	char curByte = bytecode[0];
	lastByteAppend(lastByte, curByte, temp);
	
	for (int i = 1; i < bytecode.length(); i++) {
		if (lastByte == bytecode[i])
			temp += "0";
		else {
			res += temp + " ";
			lastByteAppend(lastByte, bytecode[i], temp);
		}
	}
	res += temp;

	return res;
}



string getInitialData() {
	string message;
	string messageBytes = "";
	getline(cin, message);
	for (int i = 0; i< message.length(); i++){
		char temp = message[i];
		string binary = std::bitset<8>(temp).to_string();
		messageBytes += binary;
	}
	return messageBytes;
}

int main() {

	string messageBytes = getInitialData();
	string norrisUnarcode = _getNorrisCode(messageBytes);
	cout << messageBytes<<endl;
	cout << norrisUnarcode << endl;
	char endOfProgram;
	cin >> endOfProgram;
}