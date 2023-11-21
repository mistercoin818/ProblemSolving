#include <iostream>
using namespace std;
int T, N, M;
int combination(int m, int n){
    long long ret = 1;
    for(int i = 1; i <=n; ++i){
        ret *= m;
        --m;
        ret /= i;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    for(int t = 0; t < T; ++t){
        cin >> N >> M;
        cout << combination(M, N) << '\n';
    }
}