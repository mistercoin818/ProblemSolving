#include <iostream>
using namespace std;
int T, Q, D, N, P;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int t = 0; t < T; ++t){
    	int C;
        cin >> C;
        Q = C / 25;
        C %= 25;
        D = C / 10;
        C %= 10;
        N = C / 5;
        C %= 5;
        P = C;
        cout << Q << ' ' << D << ' ' << N << ' ' << P << '\n';
    }
}