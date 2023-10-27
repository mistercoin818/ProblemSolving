#include <iostream>
using namespace std;
int N, cnt;
bool a[100][100];
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int n = 0; n < N; ++n){
        int y, x;
        cin >> x >> y;
        for(int i = y; i < y + 10; ++i){
            for(int j = x; j < x + 10; ++j){
                a[i][j] = true;
            }
        }
    }
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            if(a[i][j]) ++cnt;
        }
    }
    cout << cnt;
}