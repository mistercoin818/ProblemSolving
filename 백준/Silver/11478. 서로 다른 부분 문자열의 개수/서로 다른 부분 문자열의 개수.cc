#include <iostream>
#include <unordered_set>
using namespace std;
string S;
unordered_set<string> s;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> S;
    int l = S.length();
    for(int i = 1; i <= l; ++i){
        for(int j = 0; j <= l - i; ++j){
            s.insert(S.substr(j, i));
        }
    }
    cout << s.size();
}