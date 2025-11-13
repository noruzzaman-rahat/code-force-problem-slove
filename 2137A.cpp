#include <bits/stdc++.h>
using namespace std;

class CollatzSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            long long k, x;
            cin >> k >> x;

            long long ans = x;
            // Reverse k steps using x_prev = 2 * x
            while (k--) {
                ans = ans * 2;
            }

            cout << ans << "\n";
        }
    }
};

int main() {
    CollatzSolver solver;
    solver.solve();
    return 0;
}

