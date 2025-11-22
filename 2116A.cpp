#include <bits/stdc++.h>
using namespace std;

class GellyfishGameSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            long long a, b, c, d;
            cin >> a >> b >> c >> d;

            bool gellyWins;

            if (b <= c) {

                if (a >= d || b <= a) {
                    gellyWins = true;
                } else {
                    gellyWins = false;
                }
            } else {
                // b > c
                if (a < d) {
                    gellyWins = false;
                } else {
                    if (d <= c) gellyWins = true;
                    else        gellyWins = false;
                }
            }

            cout << (gellyWins ? "Gellyfish" : "Flower") << "\n";
        }
    }
};

int main() {
    GellyfishGameSolver solver;
    solver.solve();
    return 0;
}

