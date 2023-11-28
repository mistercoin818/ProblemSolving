#include<iostream>
#include <vector>
using namespace std;
int T;
vector<string> split(string input, string delimiter){
	long long pos = 0;
	vector<string> ret;
	string token = "";
	while((pos=input.find(delimiter)) != string::npos){
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos+delimiter.length());
	}
	ret.push_back(input);
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> T;
	cin.ignore();
	for(int t = 0; t < T; ++t){
		string line, delimiter = " ";
		getline(cin, line);
		vector<string> a = split(line, delimiter);
		int l = a.size();
		for(int i = 0; i < l; ++i){
			for(int j = a[i].size()-1; j >= 0; --j){
				cout << a[i][j];
			}
			cout << ' ';
		}
		if(t!=T-1) cout << '\n';
	}
}