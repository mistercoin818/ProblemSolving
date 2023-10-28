#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
int N;
struct compare{
	bool operator()(int a, int b){
		if(abs(a) != abs(b)) return abs(a) > abs(b);
		return a > b;
	}
};
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, compare> pq;
    cin >> N;
    for(int i = 0; i < N; ++i){
        int x;
        cin >> x;
        if(x){
            pq.push(x);
        }
        else{
            if(pq.empty()) cout << "0\n";
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}