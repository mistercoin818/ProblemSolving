#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, cnt, in;
vector<pair<pair<int, int>, bool>> v;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; ++i){
		int a;
		cin >> a;
		v.push_back({{a, i}, true});
	}
	do{
		v[in].second = false;
		cout << v[in].first.second << ' ';
		++cnt;
		if(cnt == N) break;
		bool isPos;
		if(v[in].first.first > 0){
			isPos = true;
		}
		else{
			isPos = false;
		}
		int count = abs(v[in].first.first);
		while(count){
			if(isPos){
				in = (in + 1) % N;
			}
			else{
				in = (in + N - 1) % N;
			}
			if(v[in].second == true) --count;
		}
	}while(cnt <= N);
}