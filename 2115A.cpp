#include <bits/stdc++.h>
using namespace std;

class GellyfishFlamingPeonySolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }


            int g = 0;
            for (int v : a) {
                g = std::gcd(g, v);
            }


            int cntg = 0;
            for (int v : a) {
                if (v == g) ++cntg;
            }

            if (cntg > 0) {

                cout << (n - cntg) << "\n";
                continue;
            }


            const int MAXA = 5000;
            const int INF = (int)1e9;


            sort(a.begin(), a.end());
            a.erase(unique(a.begin(), a.end()), a.end());

            vector<int> dp(MAXA + 1, INF), newdp(MAXA + 1);


            for (int v : a) {
                newdp = dp;
                newdp[v] = min(newdp[v], 1);

                for (int gv = 1; gv <= MAXA; ++gv) {
                    if (dp[gv] == INF) continue;
                    int h = std::gcd(gv, v);
                    if (newdp[h] > dp[gv] + 1) {
                        newdp[h] = dp[gv] + 1;
                    }
                }
                dp.swap(newdp);
            }

            int L = dp[g];


            int answer = n + L - 2;
            cout << answer << "\n";
        }
    }
};

int main() {
    GellyfishFlamingPeonySolver solver;
    solver.solve();
    return 0;
}
