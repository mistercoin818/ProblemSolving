#include <iostream>

using namespace std;
int A, B, C;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
    cin >> A >> B >> C;
    cout << (A + (B+C)/60)%24 << ' ' << (B+C)%60;
}