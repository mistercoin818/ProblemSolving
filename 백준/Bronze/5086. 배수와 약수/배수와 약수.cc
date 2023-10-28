#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    while(true){
        int f, s;
        cin >> f >> s;
        if(f == 0 && s == 0) break;
        if((s / f) && !(s%f)){
            cout << "factor\n";
        }
        else if((f/s) && !(f%s)){
            cout << "multiple\n";
        }
        else{
            cout << "neither\n";
        }
    }
}