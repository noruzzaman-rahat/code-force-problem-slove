#include <bits/stdc++.h>
using namespace std;

class PasswordSolver {
public:
    int solveCase(int k, int x) {
        return k * x + 1;
    }

    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            int k, x;
            cin >> k >> x;
            cout << solveCase(k, x) << "\n";
        }
    }
};

int main() {
    PasswordSolver solver;
    solver.solve();
    return 0;
}

