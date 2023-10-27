#include <iostream>
using namespace std;
int N, M, basket[101];
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int n = 1; n <= N; ++n){
        basket[n] = n;
    }
    for(int m = 0; m < M; ++m){
        int i, j, tmp;
        cin >> i >> j;
        int l = (j - i) / 2;
        for(int index = 0; index <= l; ++index){
            tmp = basket[i + index];
            basket[i + index] = basket[j - index];
            basket[j - index] = tmp;
        }
    }
    for(int n = 1; n <= N; ++n){
        cout << basket[n] << ' ';
    }
}