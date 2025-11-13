#include <bits/stdc++.h>
using namespace std;

class CakeAssignment {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            long long k, x;
            cin >> k >> x;

            long long total = 1LL << (k + 1);
            long long mid   = 1LL << k;

            if (x == mid) {
                cout << 0 << "\n\n";
                continue;
            }

            vector<int> opsBack;

            while (x != mid) {
                long long other = total - x;

                if (x < other) {

                    x <<= 1;
                    opsBack.push_back(1);
                } else {

                    x -= other;
                    opsBack.push_back(2);
                }
            }

            int n = (int)opsBack.size();
            cout << n << "\n";

            if (n > 0) {

                for (int i = n - 1; i >= 0; --i) {
                    cout << opsBack[i];
                    if (i) cout << ' ';
                }
                cout << "\n";
            } else {

                cout << "\n";
            }
        }
    }
};

int main() {
    CakeAssignment solver;
    solver.solve();
    return 0;
}

