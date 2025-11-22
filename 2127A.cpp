#include <bits/stdc++.h>
using namespace std;

class MixMexMaxSolver {
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

            int val = -1;
            bool ok = true;

            for (int i = 0; i < n; ++i) {
                if (a[i] == -1) continue;
                if (a[i] == 0) {
                    ok = false;
                    break;
                }
                if (val == -1) {
                    val = a[i];
                } else if (a[i] != val) {
                    ok = false;
                    break;
                }
            }

            cout << (ok ? "YES" : "NO") << "\n";
        }
    }
};

int main() {
    MixMexMaxSolver solver;
    solver.solve();
    return 0;
}

