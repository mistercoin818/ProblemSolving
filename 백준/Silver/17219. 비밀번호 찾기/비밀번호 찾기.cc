#include <iostream>
#include <map>

using namespace std;
int N, M;
map<string, string> m;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string site;
		string pw;
		cin >> site >> pw;
		m.insert({ site, pw });
	}
	for (int i = 0; i < M; ++i) {
		string site;
		cin >> site;
		map<string, string>::iterator iter = m.find(site);
		cout << iter->second << '\n';
	}
}