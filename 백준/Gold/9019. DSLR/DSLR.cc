#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;

int T, A, B;
bool hadpp[10000];
string ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> A >> B;
        string order = "";
        queue<pair<int, string>> can;
        can.push({ A, order });
        hadpp[A] = true;
        while (!can.empty()) {
            int a;
            string order;
            tie(a, order) = can.front(); 
            if (a * 2 % 10000 == B) {
                ans = order + "D";
                break;
            }
            else if (!hadpp[a * 2 % 10000]) {
                hadpp[a * 2 % 10000] = true;
                can.push({ a * 2 % 10000, order + "D" });
            }
            int b;
            if (a != 0) b = a - 1;
            else b = 9999;
            if (b == B) {
                ans = order + "S";
                break;
            }
            else if (!hadpp[b]) {
                hadpp[b] = true;
                can.push({ b, order + "S" });
            }
            if (a / 1000 + ((a % 1000) * 10) == B) {
                ans = order + "L";
                break;
            }
            else if (!hadpp[a / 1000 + ((a % 1000) * 10)]) {
                hadpp[a / 1000 + ((a % 1000) * 10)] = true;
                can.push({ a / 1000 + ((a % 1000) * 10), order + "L" });
            }
            if (a / 10 + ((a % 10) * 1000) == B) {
                ans = order + "R";
                break;
            }
            else if (!hadpp[a / 10 + ((a % 10) * 1000)]) {
                hadpp[a / 10 + ((a % 10) * 1000)] = true;
                can.push({ a / 10 + ((a % 10) * 1000), order + "R" });
            }
            can.pop();
        }
        cout << ans << '\n';
        memset(hadpp, false, sizeof(hadpp));
    }
    return 0;
}
