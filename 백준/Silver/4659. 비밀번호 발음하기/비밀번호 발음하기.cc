#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
string line;

bool isVowel(char a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
		return true;
	}
	return false;
}

bool hasVowel(string line) {
	int l = line.length();
	for (int i = 0; i < l; ++i) {
		if (isVowel(line[i])) {
			return true;
		}
	}
	return false;
}

bool checkThreeSameTypeInARow(string line) {
	int l = line.length();
	if (l <= 2) {
		return true;
	}
	bool before2 = isVowel(line[0]);
	bool before = isVowel(line[1]);
	for (int i = 2; i < l; ++i) {
		if (before2 == before && before == isVowel(line[i])) {
			return false;
		}
		before2 = before;
		before = isVowel(line[i]);
	}
	return true;
}

bool checkSameLetterTwiceInARow(string line) {
	int l = line.length();
	if (l == 1) {
		return true;
	}
	char before = line[0];
	for (int i = 1; i < l; ++i) {
		if (before == line[i]) {
			if (line[i] == 'e' || line[i] == 'o') {
				before = line[i];
				continue;
			}
			else {
				return false;
			}
		}
		else {
			before = line[i];
		}
	}
	return true;
}

int main() {
	string line;
	while (true) {
		getline(cin, line);
		if (line == "end") {
			break;
		}
		else {
			if (hasVowel(line) && checkSameLetterTwiceInARow(line) && checkThreeSameTypeInARow(line)) {
				cout << '<' << line << "> is acceptable." << endl;
			}
			else {
				cout << '<' << line << "> is not acceptable." << endl;
			}
		}
		
	}
}