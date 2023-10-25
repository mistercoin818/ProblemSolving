#include <iostream>
#include <vector>
#include <string>

using namespace std;
string expression;
vector<int> num;
vector<int> minusIndex;
int cnt;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> expression;
	int l = expression.length();
	int last = 0;
	for (int i = 0; i < expression.length(); ++i) {
		if (expression[i] == '+' || expression[i] == '-') {
			num.push_back(stoi(expression.substr(last, i - last)));
			last = i + 1;
			if (expression[i] == '-') {
				minusIndex.push_back(cnt++);
			}
			else {
				cnt++;
			}
		}
		if (i == expression.length() - 1) {
			num.push_back(stoi(expression.substr(last, i - last + 1)));
		}
	}
	int sum = 0;
	if (!minusIndex.size()) {
		for (int i = 0; i < num.size(); ++i) {
			sum += num[i];
		}
		cout << sum;
	}
	else {
		for (int i = 0; i <= minusIndex[0]; ++i) {
			sum += num[i];
		}
		if (minusIndex.size() >= 2) {
			for (int i = 0; i <= minusIndex.size() - 2; ++i) {
				int temp = 0;
				for (int j = minusIndex[i] + 1; j <= minusIndex[i + 1]; ++j) {
					temp += num[j];
				}
				sum -= temp;
			}
		}
		int temp = 0;
		for (int i = minusIndex[minusIndex.size() - 1]+1; i <= num.size() - 1; ++i) {
			temp += num[i];
		}
		sum -= temp;
		cout << sum;
	}
}