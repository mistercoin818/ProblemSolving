#include <iostream>

using namespace std;
int N, cnt, arr[100], v;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }
    cin >> v;
    for(int i = 0; i < N; ++i){
        if(v == arr[i]) ++cnt;
    }
    cout << cnt;
}