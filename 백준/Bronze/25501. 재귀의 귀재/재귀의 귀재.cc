#include<iostream>
using namespace std;
int T;
int main(){
    cin >> T;
    for(int t = 0; t < T; ++t){
        string S;
        cin >> S;
        int l = S.length(), half = l / 2, i = 0;
        bool isPalindrome = true;
        for(i = 0; i < half; ++i){
            if(S[i] != S[l-1-i]){
                isPalindrome = false;
                break;
            }
        }
        cout << isPalindrome << ' ';
        if(!isPalindrome) cout << i+1;
        else cout << i+1;
        cout << '\n';
    }
}