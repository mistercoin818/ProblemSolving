#include<iostream>
#include<map>
#include<vector>
using namespace std;
int N;
map<string, int> ma;
vector<string> split(string input, string delimiter){
    long long pos = 0;
    vector<string> ret;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i){
        string str;
        getline(cin, str);
        string delimiter = " ";
        vector<string> a = split(str, delimiter);
        ma["ChongChong"] = 1;
        map<string,int>::iterator iter = ma.find(a[0]);
        map<string,int>::iterator it = ma.find(a[1]);
        if(iter != ma.end() && iter->second){
               ma[a[1]] = 1;
        }
        else if(it != ma.end() && it->second){
        	ma[a[0]] = 1;
        }
        else{
            ma[a[0]] = 0;
            ma[a[1]] = 0;
        }
    }
    map<string, int>::iterator it;
    int cnt = 0;
    for(it = ma.begin(); it != ma.end(); ++it){
        if(it->second) ++cnt;
    }
    cout << cnt;
}