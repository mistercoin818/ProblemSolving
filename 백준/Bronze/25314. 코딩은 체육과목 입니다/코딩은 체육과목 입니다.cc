#include <iostream>

using namespace std;
int N;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
    cin >> N;
    int n = N / 4;
    for(int i = 0; i < n; ++i){
        cout << "long ";
    }
    cout << "int";
}