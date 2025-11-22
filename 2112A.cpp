#include <bits/stdc++.h>
using namespace std;

class RaceSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int a, x, y;
            cin >> a >> x >> y;

            int Dx = abs(a - x);
            int Dy = abs(a - y);


            int Lx = x - Dx + 1;
            int Rx = x + Dx - 1;

            int Ly = y - Dy + 1;
            int Ry = y + Dy - 1;

            int L = max(Lx, Ly);
            int R = min(Rx, Ry);

            if (L <= R) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
};

int main() {
    RaceSolver solver;
    solver.solve();
    return 0;
}

