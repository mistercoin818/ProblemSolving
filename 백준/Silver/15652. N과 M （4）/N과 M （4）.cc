#include<iostream>
#include<deque>
using namespace std;
int N, M;
deque<int> dq;
void go(int last, int cnt){
    if(cnt == M){
        deque<int>::iterator iter;
        for(iter = dq.begin(); iter != dq.end(); ++iter){
            cout << *iter << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = last; i <= N; ++i){
        dq.push_back(i);
        go(i, cnt+1);
        dq.pop_back();
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    go(1, 0);
}