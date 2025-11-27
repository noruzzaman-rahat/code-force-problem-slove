#include <bits/stdc++.h>
using namespace std;

class FashionableArraySolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }

            const int MAXV = 50;
            vector<int> freq(MAXV + 1, 0);
            for (int v : a) {
                freq[v]++;
            }


            vector<int> pref(MAXV + 1, 0);
            for (int v = 1; v <= MAXV; ++v) {
                pref[v] = pref[v - 1] + freq[v];
            }

            auto rangeCount = [&](int L, int R) -> int {
                if (L > R) return 0;
                return pref[R] - pref[L - 1];
            };

            int best = 1;
            for (int m = 1; m <= MAXV; ++m) {
                if (freq[m] == 0) continue;
                for (int M = m; M <= MAXV; ++M) {
                    if (freq[M] == 0) continue;
                    if ((m + M) % 2 != 0) continue;

                    int cnt = rangeCount(m, M);
                    if (cnt > best) best = cnt;
                }
            }

            int answer = n - best;
            cout << answer << "\n";
        }
    }
};

int main() {
    FashionableArraySolver solver;
    solver.solve();
    return 0;
}

