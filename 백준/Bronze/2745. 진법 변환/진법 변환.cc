#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int B, l, sum;
string N;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> N >> B;
    l = N.length();
    for(int i = l -1; i >= 0; --i){
        if('0'<= N[i] && N[i] <= '9'){
            sum += (int)(N[i]-'0') * (int)pow(B, l-1-i);
        }
        else{
            sum += ((int)(N[i]-'A')+10) * (int)pow(B, l-1-i);
        }
    }
    cout << sum;
}