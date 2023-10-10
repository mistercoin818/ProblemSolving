#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		string line;
		getline(cin, line);
		if (line == ".") {
			break;
		}
		int l = line.length();
		stack<int> parentheses;
		stack<int> brackets;
		stack<char> total;
		bool parenthesesFlag = true;
		bool bracketsFlag = true;
		for (int i = 0; i < l; ++i) {
			if (line[i] == '(') {
				parentheses.push(i);
				total.push('(');
			}
			if (line[i] == ')') {
				if (parentheses.empty()) {
					parenthesesFlag = false;
					break;
				}
				if (total.top() != '(') {
					break;
				}
				parentheses.pop();
				total.pop();
			}
			if (line[i] == '[') {
				brackets.push(i);
				total.push('[');
			}
			if (line[i] == ']') {
				if (brackets.empty()) {
					bracketsFlag = false;
					break;
				}
				if (total.top() != '[') {
					break;
				}
				brackets.pop();
				total.pop();
			}
		}
		if (parentheses.empty() && parenthesesFlag && brackets.empty() && bracketsFlag && total.empty()) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}