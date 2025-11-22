#include <bits/stdc++.h>
using namespace std;

class FarmLegsSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;

            if (n % 2 == 1) {
                cout << 0 << "\n";
            } else {
                cout << (n / 4) + 1 << "\n";
            }
        }
    }
};

int main() {
    FarmLegsSolver solver;
    solver.solve();
    return 0;
}

