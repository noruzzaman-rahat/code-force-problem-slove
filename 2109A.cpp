#include <bits/stdc++.h>
using namespace std;

class ItsTimeToDuelSolver {
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


            vector<array<bool,2>> dp(n);


            if (a[1] == 0) {
                dp[1][0] = false;
                dp[1][1] = true;
            } else {
                dp[1][0] = true;
                dp[1][1] = false;
            }


            for (int i = 2; i <= n - 1; ++i) {
                dp[i][0] = dp[i][1] = false;
                for (int prev = 0; prev <= 1; ++prev) {
                    if (!dp[i-1][prev]) continue;
                    for (int cur = 0; cur <= 1; ++cur) {
                        bool ok = false;
                        if (a[i] == 0) {

                            if (prev == 0 && cur == 1) ok = true;
                        } else { // a[i] == 1



                            if (prev == 1 || cur == 0) ok = true;
                        }
                        if (ok) dp[i][cur] = true;
                    }
                }
            }


            bool possible = false;
            if (n == 2) {

                for (int v = 0; v <= 1; ++v) {
                    if (!dp[1][v]) continue;
                    if ((a[2] == 0 && v == 0) || (a[2] == 1 && v == 1)) {
                        possible = true;
                    }
                }
            } else {
                for (int v = 0; v <= 1; ++v) {
                    if (!dp[n-1][v]) continue;
                    if ((a[n] == 0 && v == 0) || (a[n] == 1 && v == 1)) {
                        possible = true;
                    }
                }
            }


            cout << (possible ? "NO\n" : "YES\n");
        }
    }
};

int main() {
    ItsTimeToDuelSolver solver;
    solver.solve();
    return 0;
}

