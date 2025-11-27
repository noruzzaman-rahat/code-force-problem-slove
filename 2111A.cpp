#include <bits/stdc++.h>
using namespace std;

class EnergyCrystalsSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            long long x;
            cin >> x;


            int t = 63 - __builtin_clzll(x);

            long long ans = 2LL * t + 3LL;
            cout << ans << "\n";
        }
    }
};

int main() {
    EnergyCrystalsSolver solver;
    solver.solve();
    return 0;
}

