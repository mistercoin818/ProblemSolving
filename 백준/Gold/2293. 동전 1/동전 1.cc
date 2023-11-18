#include <iostream>
using namespace std;
int n, k, arr_n[101], arr_k[10001];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> arr_n[i];
	}
	arr_k[0] = 1;
	for(int i = 1; i <=n; ++i){
		for(int j = arr_n[i]; j <= k; ++j){
			arr_k[j] += arr_k[j-arr_n[i]];
		}
	}
	cout << arr_k[k];
}