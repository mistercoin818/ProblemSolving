#include<iostream>
#include<vector>
#include <set>
using namespace std;
int N, M;
vector<int> v, vv;
set<vector<int>> s;
bool visited[8];
void go(int index, int cnt){
    if(cnt == M){
        s.insert(vv);
        return;
    }
    for(int i = 0; i < N; ++i){
    	if(visited[i])continue;
        vv.push_back(v[i]);
        visited[i]=true;
        go(i, cnt+1);
        visited[i]=false;
        vv.pop_back();
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        int a;
        cin >> a;
        v.push_back(a);
    }
    // sort(v.begin(), v.end());
    go(0, 0);
    for(auto x:s){
        for(int i = 0; i < M; ++i){
            cout << x[i] << ' ';
        }
        cout << '\n';
    }
}