#include <iostream>
#include <cmath>
using namespace std;
int T;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int t = 0; t < T; ++t){
        long long n;
        cin >> n;
        bool flag = true;
        while(flag){
            bool flagg = false;
            if(n==0 || n ==1) ++n;
            else if(n==2) flag = false;
            else{
                int r = (int)sqrt(n);
                for(int i = 2; i <= r; ++i){
                    if(!(n % i)){
                        flagg = true;
                        break;
                    }
                }
                if(!flagg) flag = false;
                else ++n;
            }
        }
        cout << n << '\n';
    }
}