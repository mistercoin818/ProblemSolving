#include <iostream>
#include <vector>
using namespace std;
int N, K;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= N; ++i){
        if(!(N%i)) v.push_back(i);
    }
    if(v.size() < K) cout << 0;
    else cout << v[K-1];
}