#include <iostream>
#include <algorithm>
using namespace std;
int a[5], sum;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 5; ++i){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+5);
    cout << sum / 5 << '\n' << a[2];
}