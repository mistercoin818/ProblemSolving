#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100000;

int main(){
	int N;
	cin >> N;
	char v[MAX + 1];
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	
	long long d, k, s, h;
	d = 0, k = 0, s = 0, h = 0;
	
	for(int i = 0; i < N; i++){
		if(v[i] == 'D'){
			d++;
		}
		else if(v[i] == 'K'){
			k += d;
		}
		else if(v[i] == 'S'){
			s += k;
		}
		else if(v[i] == 'H'){
			h += s;
		}
	}
	cout << h;
}