#include <iostream>
#include <string>
using namespace std;
char a[5][15];
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 5; ++i){
        string s;
        cin >> s;
        int l = s.length();
        for(int j = 0; j < l; ++j){
            a[i][j] = s[j];
        }
        for(int j = l; j < 15; ++j){
            a[i][j] = '!';
        }
    }
    for(int j = 0; j < 15; ++j){
        for(int i = 0; i < 5; ++i){
        	if(a[i][j] != '!') cout << a[i][j];
        }
    }
}