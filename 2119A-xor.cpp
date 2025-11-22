#include <bits/stdc++.h>
using namespace std;

class AddOrXORSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            long long a, b, x, y;
            cin >> a >> b >> x >> y;

            if (a == b) {
                cout << 0 << "\n";
                continue;
            }


            if (b < a) {
                if (a % 2 == 1 && b == a - 1) {

                    cout << y << "\n";
                } else {
                    cout << -1 << "\n";
                }
                continue;
            }


            long long D = b - a;
            long long ce = min(x, y);

            long long cur = a;
            long long cost = 0;
            for (long long i = 0; i < D; ++i) {
                if (cur % 2 == 0) {

                    cost += ce;
                } else {

                    cost += x;
                }
                ++cur;
            }

            cout << cost << "\n";
        }
    }
};

int main() {
    AddOrXORSolver solver;
    solver.solve();
    return 0;
}

