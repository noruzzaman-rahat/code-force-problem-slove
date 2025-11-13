#include <bits/stdc++.h>
using namespace std;

class InTheDream {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            int r1 = a;
            int k1 = b;
            int r2 = c - a;
            int k2 = d - b;

            bool ok1 = canHalf(r1, k1);
            bool ok2 = canHalf(r2, k2);

            if (ok1 && ok2) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

private:
    bool canHalf(int r, int k) {
        int M = max(r, k);
        int N = min(r, k);
        return M <= 2 * (N + 1);
    }
};

int main() {
    InTheDream solver;
    solver.solve();
    return 0;
}

