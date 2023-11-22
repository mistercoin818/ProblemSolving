#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i){
        int A;
        cin >> A;
        v.push_back(A);
    }
    sort(v.begin(), v.end());
    if(N%2) cout << v[(int)(N/2)]*v[(int)(N/2)];
    else cout << v[N-1]*v[0];
}