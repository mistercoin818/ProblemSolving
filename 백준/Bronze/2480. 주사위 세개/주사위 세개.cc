#include <iostream>
#include <algorithm>

using namespace std;
int a, b, c;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    if(a==b && b==c) cout << 10000+a*1000;
    else if(a!=b & b!=c && c!=a) cout << max(max(a, b), c)*100;
    else if(a == b || a ==c) cout << 1000+100*a;
    else cout << 1000+100*b;
}