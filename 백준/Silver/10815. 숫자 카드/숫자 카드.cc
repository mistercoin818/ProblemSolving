#include <iostream>
#include <set>
using namespace std;
int N, M;
set<int> s;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        int a;
        cin >> a;
        s.insert(a);
    }
    cin >> M;
    for(int i = 0; i < M; ++i){
        int a;
        cin >> a;
        set<int>::iterator it = s.find(a);
        if(it != s.end()) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
}