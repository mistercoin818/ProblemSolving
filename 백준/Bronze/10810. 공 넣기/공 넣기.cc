#include <iostream>
using namespace std;
int N, M, basket[101];
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int m = 0; m < M; ++m){
        int i, j, k;
        cin >> i >> j >> k;
        for(int index = i; index <= j; ++index){
            basket[index] = k;
        }
    }
    for(int n = 1; n <= N; ++n){
        cout << basket[n] << ' ';
    }
}