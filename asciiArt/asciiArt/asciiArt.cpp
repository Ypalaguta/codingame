// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/

class asciiLetters {
private:
	int _lettersCount;
	int _charWidth;
	int _charHeight;
	char* _inputLetters;
	int _rowProcessed;
	string _wordToPrint;
	map<char, string> _letters;
	void _setLetters(string lettersRow) {
		for (int i = 0; i < _lettersCount * _charWidth; i += _charWidth) {		// sring of chars with _charWidth width
			string temp = "";									//current char
			for (int j = i; j < i + _charWidth; j++)
				temp += lettersRow[j];
			int currentLetterNum = i / _charWidth;
			char currentLetter = _inputLetters[currentLetterNum];		//current letter to set ascii char
			if (_rowProcessed == 0)
				_letters.insert(pair<char, string>(currentLetter, temp));		//add current char to map - dangerous moment
			else
				_letters[currentLetter] += temp;								//append ascii to created char -- dangerous 2
		}
		_rowProcessed++;
	};

	string _getLetter(char letter, int rowNumber) {
		string result;
		for (int i = rowNumber * _charWidth; i < (rowNumber * _charWidth) + _charWidth; i++)
			result += _letters[letter][i];
		return result;
	};
	void _replaceSpecSymboldAtWordToPrint() {
		transform(_wordToPrint.begin(), _wordToPrint.end(), _wordToPrint.begin(), ::toupper);
		regex long_word_regex("[^a-zA-Z]");
		string _wordToPrint = regex_replace(_wordToPrint, long_word_regex, "?");
	};
public:
	asciiLetters() {
		_rowProcessed = 0;
		_lettersCount = 27;
		_inputLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
	};
	void fillLetters() {
		for (int i = 0; i < _charHeight; i++) {
			string ROW;
			getline(cin, ROW);
			_setLetters(ROW);
		}
	};

	void getInitialData() {
		cin >> _charWidth; cin.ignore();
		cin >> _charHeight; cin.ignore();
		getline(cin, _wordToPrint);
		_replaceSpecSymboldAtWordToPrint();
	};


	void printWord() {
		//_wordToPrint
		for (int i = 0; i < _charHeight; i++) {
			for (int j = 0; j < _wordToPrint.length(); j++) {
				char currentLetter = _wordToPrint[j];
				int letterLevel = i * _charWidth;
				for (int k = letterLevel; k < letterLevel + _charWidth; k++)
					cout << _letters[currentLetter][k];
			}
			cout << endl;
		}
	}
};



int main() {
	asciiLetters currentWord = asciiLetters();
	currentWord.getInitialData();
	currentWord.fillLetters();
	currentWord.printWord();
}