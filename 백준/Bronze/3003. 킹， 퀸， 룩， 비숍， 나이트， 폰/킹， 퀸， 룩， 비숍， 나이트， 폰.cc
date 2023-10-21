#include<iostream>
using namespace std;
int a[6] ={1,1,2,2,2,8};
int main(){
    cin.tie(NULL); cout.tie(NULL);ios::sync_with_stdio(false);
    for(int i = 0; i < 6;++i){
        int b;
        cin >> b;
        cout << a[i]-b << ' ';
    }
}