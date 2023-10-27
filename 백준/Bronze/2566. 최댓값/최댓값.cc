#include <iostream>
using namespace std;
int a[10][10], M = -1, y, x;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    for(int i = 1; i <= 9; ++i){
        for(int j = 1; j <= 9; ++j){
            cin >> a[i][j];
            if(a[i][j] > M){
                M = a[i][j];
                y = i;
                x = j;
            }
        }
    }
    cout << M << '\n' << y << ' ' << x;
}