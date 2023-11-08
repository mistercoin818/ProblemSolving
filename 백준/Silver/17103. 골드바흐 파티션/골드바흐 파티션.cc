#include <iostream>
#include <vector>
using namespace std;
int T;
bool arr[1000001];
vector<int> v;
bool isPrime(int k){
    for(int i = 3; i * i <= k; i+=2){
        if(!(k%i)) return false;
    }
    return true;
}
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int i = 3; i < 1000000; i+=2){
        if(isPrime(i)){
            arr[i] = true;
            v.push_back(i);
        } 
    }
    for(int t = 0; t < T; ++t){
        int N, cnt = 0;
        cin >> N;
        int half = N / 2;
        if(N==4) cout << 1 << '\n';
        else{
            int i = 0;
            while(v[i] <= half){
                if(arr[N-v[i]]) ++cnt;
                ++i;
            }
            cout << cnt << '\n';
        }
    }
}