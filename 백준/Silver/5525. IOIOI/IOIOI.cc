#include <iostream>
using namespace std;
int N, M, cnt;
string S, s = "I";
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin >> S;
    for(int i = 0; i < N; ++i){
        s += "OI";
    }
    int l = s.length();
    for(int i = 0; i <= M -l; ++i){
        if(S[i] == 'O') continue;
        else{
            string tmp = S.substr(i, l);
            if(tmp == s) ++cnt;
        }
    }
    cout << cnt;
}