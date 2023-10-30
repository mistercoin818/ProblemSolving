#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, k;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> k;
    for(int i = 0; i < N; ++i){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<>());
    cout << v[k-1];
}