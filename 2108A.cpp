#include <bits/stdc++.h>
using namespace std;

class PermutationWarmUpSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            long long n;
            cin >> n;
            long long ans = (n * n) / 4 + 1;
            cout << ans << "\n";
        }
    }
};

int main() {
    PermutationWarmUpSolver solver;
    solver.solve();
    return 0;
}

