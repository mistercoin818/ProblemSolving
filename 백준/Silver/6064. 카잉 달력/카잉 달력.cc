#include <iostream>
#include <cstdlib>
using namespace std;
int T;
int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a=b;
		b=r;
	}
	return a;
}
int lcm(int a, int b){
	return a*b/gcd(a,b);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for(int t = 0; t < T; ++t){
		int M, N, x, y, max_m, max_n, ans = -1;
		cin >> M >> N >> x >> y;
		max_n = lcm(M, N) / N - 1;
		for(int i = 0; i <= max_n; ++i){
			if((i*N + y - x) % M == 0){
				ans = i;
				break;
			}
		}
		if(ans == -1) cout << ans << '\n';
		else cout << ans*N + y << '\n';
	}
}