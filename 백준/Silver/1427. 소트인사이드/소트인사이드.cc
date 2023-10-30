#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int l = s.length();
    for(int i = 0; i < l; ++i){
        pq.push(stoi(s.substr(i,1)));
    }
    for(int i = 0; i < l; ++i){
        cout << pq.top();
        pq.pop();
    }
}