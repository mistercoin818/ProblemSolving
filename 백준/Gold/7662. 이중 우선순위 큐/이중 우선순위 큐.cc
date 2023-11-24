#include <iostream>
#include <queue>
#include <map>
using namespace std;
int T;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> T;
	for(int t = 0; t < T; ++t){
		int k, n;
		cin >> k;
		char letter;
		priority_queue<int> pq;
		priority_queue<int, vector<int>, greater<int>> rpq;
		map<int, int> ma; map<int, int> rma;
		for(int i = 0; i < k; ++i){
			cin >> letter >> n;
			if(letter == 'I'){
				pq.push(n); rpq.push(n);
			}
			else{
				if(n == 1) {
					while(true){
						if(pq.empty()) break;
						int temp = pq.top();
						pq.pop();
						if(ma.empty()) {
							if(rma.find(temp) != rma.end()) ++rma[temp];
							else rma[temp] =1;
							break;
						}
						else{
							
							if(ma.find(temp) != ma.end()){
								--ma[temp];
								if(!ma[temp]) ma.erase(temp);
							}
							else{
								if(rma.find(temp) != rma.end()) ++rma[temp];
								else rma[temp] =1;
								break;
							}
						}
					}
				}
				else{
					while(true){
						if(rpq.empty()) break;
						int temp = rpq.top();
						rpq.pop();
						if(rma.empty()) {
							if(ma.find(temp) != ma.end()) ++ma[temp];
							else ma[temp] = 1;
							break;
						}
						else{
							if(rma.find(temp) != rma.end()){
								--rma[temp];
								if(!rma[temp]) rma.erase(temp);
							}
							else{
								if(ma.find(temp) != ma.end()) ++ma[temp];
								else ma[temp] = 1;
								break;
							}
						}
					}
				}
			}
		}
		while(rma.find(rpq.top()) != rma.end()){
			--rma[rpq.top()];
			if(!rma[rpq.top()]) rma.erase(rpq.top());
			rpq.pop();
		}
		while(ma.find(pq.top()) != ma.end()){
			--ma[pq.top()];
			if(!ma[pq.top()]) ma.erase(pq.top());
			pq.pop();
		}
		if(pq.empty() || rpq.empty()) cout << "EMPTY\n";
		else cout << pq.top() << ' ' << rpq.top() << '\n';
	}
}