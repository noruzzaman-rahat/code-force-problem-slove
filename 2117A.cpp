#include <bits/stdc++.h>
using namespace std;

class FalseAlarmSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n, x;
            cin >> n >> x;
            vector<int> a(n + 1);
            for (int i = 1; i <= n; ++i) {
                cin >> a[i];
            }

            int mn = n + 1;
            int mx = 0;
            for (int i = 1; i <= n; ++i) {
                if (a[i] == 1) {
                    mn = min(mn, i);
                    mx = max(mx, i);
                }
            }


            if (mx - mn + 1 <= x) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
};

int main() {
    FalseAlarmSolver solver;
    solver.solve();
    return 0;
}
