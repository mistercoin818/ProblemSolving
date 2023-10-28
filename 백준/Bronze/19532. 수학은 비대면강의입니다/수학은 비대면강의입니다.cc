#include <iostream>
using namespace std;
int a, b, c, d, e, f;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c >> d >> e >> f;
    int y = (c * d - a * f) / (b * d - a * e);
	int x = (c * e - b * f) / (a * e - b * d);
    cout << x << ' ' << y;
}