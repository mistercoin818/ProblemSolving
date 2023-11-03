#include <iostream>
#include <set>
using namespace std;
int N, M, cnt;
set<string> se;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        string s;
        cin >> s;
        se.insert(s);
    }
    for(int i = 0; i < M; ++i){
        string a;
        cin >> a;
        set<string>::iterator it = se.find(a);
        if(it != se.end()) ++cnt;
    }
    cout << cnt;
}