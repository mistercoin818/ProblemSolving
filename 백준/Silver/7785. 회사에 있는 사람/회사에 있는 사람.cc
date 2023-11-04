#include <iostream>
#include <set>
using namespace std;
int n;
set<string> s;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i){
        string a, b;
        cin >> a >> b;
        if(b == "enter") s.insert(a);
        else s.erase(a);
    }
    int l = s.size();
    set<string>::reverse_iterator iter;
    for(iter = s.rbegin(); iter != s.rend(); ++iter){
        cout << *iter << '\n';
    }
}