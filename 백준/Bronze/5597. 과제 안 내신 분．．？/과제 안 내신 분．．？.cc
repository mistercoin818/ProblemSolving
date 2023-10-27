#include <iostream>
using namespace std;
bool students[31];
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 28; ++i){
        int n;
        cin >> n;
        students[n] = true;
    }
    for(int n = 1; n <= 30; ++n){
        if(!students[n]) cout << n << '\n';
    }
}