#include <bits/stdc++.h>
using namespace std;

class GreedyGridSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n, m;
            cin >> n >> m;

            if (n == 1 || m == 1) {
                cout << "NO\n";
            } else if (n == 2 && m == 2) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
};

int main() {
    GreedyGridSolver solver;
    solver.solve();
    return 0;
}

