#include <iostream>

using namespace std;
int X, N, a, b;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
    cin >> X >> N;
    for(int i = 0; i < N; ++i){
        cin >> a >> b;
        X -= a*b;
    }
    if(!X) cout << "Yes";
    else cout << "No";
}