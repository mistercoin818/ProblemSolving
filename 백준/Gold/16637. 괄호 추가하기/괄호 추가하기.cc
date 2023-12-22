#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int N;
long long maxi = INT_MIN;
string expr;
void go(int index, long long before, long long temp, char op, bool isOpen) {
	if(N == 1){
		maxi = expr[0] - '0';
		return;
	}
	if (index == N - 1) {
		long long secondOne;
		if (isOpen) {
			if (expr[index - 1] == '+') {
				secondOne = temp + expr[index] - '0';
			}
			else if (expr[index - 1] == '-') {
				secondOne = temp - (expr[index] - '0');
			}
			else {
				secondOne = temp * (expr[index] - '0');
			}
		}
		else {
			secondOne = expr[index] - '0';
			op = expr[index - 1];
		}
		if (op == '+') {
			maxi = max(maxi, before + secondOne);
		}
		else if (op == '-') {
			maxi = max(maxi, before - secondOne);
		}
		else {
			maxi = max(maxi, before * secondOne);
		}
		return;
	}
	if (index) {
		long long secondOne;
		if (isOpen) {
			if (expr[index - 1] == '+') {
				secondOne = temp + expr[index] - '0';
			}
			else if (expr[index - 1] == '-') {
				secondOne = temp - (expr[index] - '0');
			}
			else {
				secondOne = temp * (expr[index] - '0');
			}
			//go(index + 2, before, secondOne, op, true);
			if (op == '+') {
				go(index + 2, before + secondOne, 0L, op, false);
			}
			else if (op == '-') {
				go(index + 2, before - secondOne, 0L, op, false);
			}
			else {
				go(index + 2, before * secondOne, 0L, op, false);
			}
		}
		else {
			secondOne = expr[index] - '0';
			go(index + 2, before, secondOne, expr[index - 1], true);
			if (expr[index - 1] == '+') {
				before += expr[index] - '0';
			}
			else if (expr[index - 1] == '-') {
				before -= expr[index] - '0';
			}
			else {
				before *= expr[index] - '0';
			}
			go(index + 2, before, 0L, expr[index - 1], false);
		}
	}
	else {
		go(index + 2, expr[index] - '0', temp, expr[1], false);
		go(index + 2, before, expr[index] - '0', op, true);
	}
	return;
}
int main() {
	cin >> N >> expr;
	go(0, 0L, 0L, '+', false);
	cout << maxi;
}