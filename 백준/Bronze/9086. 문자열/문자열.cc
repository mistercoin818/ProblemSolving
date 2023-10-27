#include <iostream>
#include <string>
using namespace std;
int T;
string line;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int t = 0; t < T; ++t){
        cin >> line;
        cout << line[0] << line[line.length()-1] << '\n';
    }
}