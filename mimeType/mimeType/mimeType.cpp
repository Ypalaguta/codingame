// mimeType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

void getInitialData(int &numberOfEls, int &filesToAnalize, map<string, string> &typeToMimeDecode) {
	cin >> numberOfEls; cin.ignore();
	cin >> filesToAnalize; cin.ignore();
	for (int i = 0; i < numberOfEls; i++) {
		string EXT; // file extension
		string MT; // MIME type.
		cin >> EXT >> MT; cin.ignore();
		std::transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
		typeToMimeDecode.insert(pair<string, string>(EXT, MT));
	}
}

string* getFilesData(int filesToAnalize) {
	string* files = new string[filesToAnalize];
	for (int i = 0; i < filesToAnalize; i++) {
		getline(cin, files[i]);
		std::transform(files[i].begin(), files[i].end(), files[i].begin(), ::tolower);
	}
	return files;
}

string getFileType(string filename) {
// /.+\./
	if (filename.find(".") != string::npos) {
		regex long_word_regex(".*?\\.");
		filename = regex_replace(filename, long_word_regex, "");
		return filename;
	}
	else
		return "UNKNOWN";
}

void showMimeTypes(map<string, string> &typeToMimeDecode, string* files, int filesLength) {
	for (int i = 0; i < filesLength; i++) {
		string currenttype = getFileType(files[i]);
		//cout << files[i] << " - " ;
		if (typeToMimeDecode.count(currenttype))
			cout << typeToMimeDecode[currenttype] << endl;
		else
			cout << "UNKNOWN" << endl;
	}
}

int main() {
	int numberOfEls, filesToAnalize;
	map<string, string> typeToMimeDecode;
	getInitialData(numberOfEls, filesToAnalize, typeToMimeDecode);
	string* files = getFilesData(filesToAnalize);
	cout << endl;
	showMimeTypes(typeToMimeDecode, files, filesToAnalize);
	// For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
	char temp;
	cin >> temp;
}