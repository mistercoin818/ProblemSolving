#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
int N, root, ret;
vector<int> nodes[50];
map<int, int> m;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int parent;
		cin >> parent;
		m.insert({ i, parent });
		if (parent != -1) {
			nodes[parent].push_back(i);
		}
		else {
			root = i;
		}
	}
	int deleteNode;
	cin >> deleteNode;
	int deleteNodeParent = m.find(deleteNode)->second;
	if (deleteNodeParent == -1) {
		cout << 0;
	}
	else {
		for (int i = 0; i < nodes[deleteNodeParent].size(); ++i) {
			if (nodes[deleteNodeParent][i] == deleteNode) {
				nodes[deleteNodeParent].erase(nodes[deleteNodeParent].begin() + i);
				break;
			}
		}
		queue<int> q;
		if (nodes[root].size()) {
			for (int i = 0; i < nodes[root].size(); ++i) {
				q.push(nodes[root][i]);
			}
			while (q.size()) {
				int x = q.front();
				q.pop();
				if (nodes[x].size()) {
					for (int i = 0; i < nodes[x].size(); ++i) {
						q.push(nodes[x][i]);
					}
				}
				else {
					++ret;
				}
			}
			cout << ret;
		}
		else {
			cout << 1;
		}
	}
}