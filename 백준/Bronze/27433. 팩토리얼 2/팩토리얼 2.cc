#include<iostream>
using namespace std;
int N;
long long factorial(int N){
    if(N == 0) return 1;
    return N * factorial(N-1);
}
int main(){
    cin >> N;
    cout << factorial(N);
}