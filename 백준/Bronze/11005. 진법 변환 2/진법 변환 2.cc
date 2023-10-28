#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, B;
string ans = "";
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	cin >> n >> B;
	int N =n;
    while(N){
        int tmp = N % B;
        char temp;
        if(tmp >= 10) temp = 'A' + tmp - 10;
        else temp = '0' + tmp;
        ans += temp;
        N /= B;
    }
    if(!n) cout << 0;
    else {
    	int ll = ans.length();
    	for(int i = ll - 1; i >= 0; --i){
    		cout<< ans[i];
    	}
    }
}