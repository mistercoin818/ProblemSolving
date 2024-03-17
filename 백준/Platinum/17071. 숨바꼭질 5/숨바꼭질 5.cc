#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, K, broPosition[1000], ans = 1001, t, l;
vector<pair<int, int>> minTime(500001, { -1, -1 });
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    broPosition[0] = K;
    q.push(N); ++l;
    minTime[N].second = 0;
    int k = 0, last_i = k;
    while (true) {
        K += ++k;
        if (K > 500000) break;
        else {
            broPosition[k] = K;
            last_i = k;
        }
    }
    while (t <= last_i && !q.empty()) {
        int l = q.size();
        for (int i = 0; i < l; ++i) {
            int a = q.front(); q.pop();
            if (t % 2) {
                if (a >= 1 && minTime[a - 1].second < 0) {
                    minTime[a - 1].second = t + 1;
                    q.push(a - 1);
                }
                if (a <= 499999 && minTime[a + 1].second < 0) {
                    minTime[a + 1].second = t + 1;
                    q.push(a + 1);
                }
                if (a <= 250000 && minTime[a * 2].second < 0) {
                    minTime[a * 2].second = t + 1;
                    q.push(a * 2);
                }
            }
            else {
                if (a >= 1 && minTime[a - 1].first < 0) {
                    minTime[a - 1].first = t + 1;
                    q.push(a - 1);
                }
                if (a <= 499999 && minTime[a + 1].first < 0) {
                    minTime[a + 1].first = t + 1;
                    q.push(a + 1);
                }
                if (a <= 250000 && minTime[a * 2].first < 0) {
                    minTime[a * 2].first = t + 1;
                    q.push(a * 2);
                }
            }
        }
        ++t;
    }
    for (int i = 0; i <= last_i; ++i) {
        if (i % 2) {
            if (minTime[broPosition[i]].first >= 0 && minTime[broPosition[i]].first <= i) {
                if (ans > i) ans = i;
            }
        }
        else {
            if (minTime[broPosition[i]].second >= 0 && minTime[broPosition[i]].second <= i) {
                if (ans > i) ans = i;
            }
        }
    }
    if (ans == 1001) ans = -1;
    cout << ans;
}