#include <bits/stdc++.h>
using namespace std;

class GoodProblemSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            long long n, l, r, k;
            cin >> n >> l >> r >> k;


            if (n & 1LL) {
                cout << l << "\n";
                continue;
            }


            if (n == 2) {
                cout << -1 << "\n";
                continue;
            }



            long long t = 1;
            while (t <= l) {
                t <<= 1;
            }


            if (t > r) {
                cout << -1 << "\n";
                continue;
            }


            if (k <= n - 2) {
                cout << l << "\n";
            } else {
                cout << t << "\n";
            }
        }
    }
};

int main() {
    GoodProblemSolver solver;
    solver.solve();
    return 0;N
}

