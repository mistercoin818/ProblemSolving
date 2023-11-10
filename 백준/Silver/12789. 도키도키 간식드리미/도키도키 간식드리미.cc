#include <iostream>
#include <stack>
using namespace std;
stack<int> s, tmp;
int N;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        int a;
        cin >> a;
        tmp.push(a);
    }
    for(int i = 0; i < N; ++i){
        int b = tmp.top();
        tmp.pop();
        s.push(b);
    }
    int check = 1;
    bool flag = true;
    while(check <= N){
        if (!s.empty() && s.top() == check) {
            s.pop();
            ++check;
        } else if (!tmp.empty() && tmp.top() == check) {
            tmp.pop();
            ++check;
        } else if (!s.empty()) {
            tmp.push(s.top());
            s.pop();
        } else {
            flag = false;
            break;
        }
    }
    if(flag) cout << "Nice";
    else cout << "Sad";
}