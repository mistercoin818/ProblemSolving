#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int T;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for(int t = 0; t < T; ++t){
		int N, mini = INT_MAX;
		cin >> N;
		vector<string> mbti;
		vector<int> check;
		for(int i = 0; i < N; ++i){
			string a;
			cin >> a;
			mbti.push_back(a);
		}
		if(N > 32) cout << 0 << '\n';
		else{
			for(int i = 0; i < 3; ++i){
				check.push_back(1);
			}
			for(int i = 0; i < N-3; ++i){
				check.push_back(0);
			}
			do{
				vector<string> temp;
				for(int i = 0; i < N; ++i){
					if(check[i]) temp.push_back(mbti[i]);
				}
				int d = 0;
				for(int i = 0; i < 3; ++i){
					int cnt = 0;
					if(i <= 1){
						for(int j = 0; j < 4; ++j){
							if(temp[i][j] != temp[i+1][j]) ++cnt;
						}
					}
					else{
						for(int j = 0; j < 4; ++j){
							if(temp[i][j] != temp[0][j]) ++cnt;
						}
					}
					d += cnt;
				}
				mini = min(d, mini);
			}while(prev_permutation(check.begin(), check.end()));
			cout << mini << '\n';
		}
	}
}