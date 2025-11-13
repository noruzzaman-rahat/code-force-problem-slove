#include <bits/stdc++.h>
using namespace std;

class AgainstTheDifference {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            vector<int> a(n + 1);
            for (int i = 1; i <= n; ++i) {
                cin >> a[i];
            }

            vector<int> dp(n + 1, 0);

            vector<deque<int>> pos(n + 1);

            for (int i = 1; i <= n; ++i) {
                int v = a[i];


                dp[i] = dp[i - 1];


                pos[v].push_back(i);
                if ((int)pos[v].size() > v) {
                    pos[v].pop_front();
                }

                if ((int)pos[v].size() == v) {
                    int startIndex = pos[v].front();
                    dp[i] = max(dp[i], dp[startIndex - 1] + v);
                }
            }

            cout << dp[n] << '\n';
        }
    }
};

int main() {
    AgainstTheDifference solver;
    solver.solve();
    return 0;
}

