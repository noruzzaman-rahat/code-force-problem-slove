#include <bits/stdc++.h>
using namespace std;

class ShashliksSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T_cases;
        cin >> T_cases;
        while (T_cases--) {
            long long k, a, b, x, y;
            cin >> k >> a >> b >> x >> y;

            long long T = k;
            long long ans = 0;

            while (true) {
                bool can1 = (T >= a);
                bool can2 = (T >= b);

                if (!can1 && !can2) break;

                long long r, d;

                if (can1 && can2) {

                    if (x <= y) {
                        r = a; d = x;
                    } else {
                        r = b; d = y;
                    }
                } else if (can1) {
                    r = a; d = x;
                } else {
                    r = b; d = y;
                }


                long long t_max = (T - r) / d + 1;
                if (t_max <= 0) break;

                ans += t_max;
                T -= t_max * d;
            }

            cout << ans << "\n";
        }
    }
};

int main() {
    ShashliksSolver solver;
    solver.solve();
    return 0;
}

