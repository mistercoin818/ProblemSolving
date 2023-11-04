#include <iostream>
#include <vector>
using namespace std;
int N, g, cnt;
bool flag;
vector<int> v;
int gcd(int A, int B){
    int c;
    while(B){
        c = A % B;
        A = B;
        B = c;
    }
    return A;
}
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int tmp;
    cin >> tmp;
    for(int i = 1; i < N; ++i){
        int n;
        cin >> n;
        v.push_back(n-tmp);
        int a = n - tmp;
        tmp = n;
        if(i==1) g = v[0];
        else {
            if(g != a){
                flag = true;
                g = gcd(g, a);
            }
        }
    }
    if(flag){
        int l = v.size();
        for(auto it: v){
            cnt += it / g - 1;
        }
        cout << cnt;
    }
    else cout << 0;
}