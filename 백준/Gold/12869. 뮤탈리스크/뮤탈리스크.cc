#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N, SCV[61][61][61];
vector<int> initialSCV(3);
queue<vector<int>> q;
bool flagg;
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> initialSCV[i];
	}
	q.push(initialSCV);
	while (!flagg) {
		vector<int> tempSCV = q.front(); q.pop();
		vector<int> hp, forPush;
		int isAlive = 0;
		for (int i = 0; i < 3; ++i) {
			if (tempSCV[i]) ++isAlive;
		}
		for (int i = 0; i < isAlive; ++i) {
			int HP = 1;
			for (int j = 0; j < 2 - i; ++j) {
				HP *= 3;
			}
			hp.push_back(HP);
		}
        do {
            int j = 0;
            for (int i = 0; i < 3; ++i) {
                if (tempSCV[i]) {
                    int temp = tempSCV[i] - hp[j] > 0 ? tempSCV[i] - hp[j] : 0;
                    ++j;
                    forPush.push_back(temp);
                }
                else forPush.push_back(0);
            }
            bool flag = true;
            for (int i = 0; i < 3; ++i) {
                if (forPush[i] > 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << SCV[tempSCV[0]][tempSCV[1]][tempSCV[2]] + 1;
                flagg = true;
                break;
            }
            if (!SCV[forPush[0]][forPush[1]][forPush[2]]) {
            	SCV[forPush[0]][forPush[1]][forPush[2]] = SCV[tempSCV[0]][tempSCV[1]][tempSCV[2]] + 1;
            	q.push(forPush);
            }
            forPush.clear();
        } while (prev_permutation(hp.begin(), hp.end()));
	}
}