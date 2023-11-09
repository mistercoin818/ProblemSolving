#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int N;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        int a;
        cin >> a;
        switch(a){
            case 1:
                int b;
                cin >> b;
                s.push(b);
                break;
            case 5:
                if(!s.empty()) cout << s.top() << '\n';
                else cout << -1 << '\n';
                break;
            case 3:
                cout << s.size() << '\n';
                break;
            case 4:
                cout << s.empty() << '\n';
                break;
            case 2:
                if(!s.empty()) {
                	cout << s.top() << '\n';
                	s.pop();
                }
                else cout << -1 << '\n';
                break;
        }
    }
}