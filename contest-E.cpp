#include <bits/stdc++.h>
using namespace std;

class BlackslexGirlsSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            int n;
            long long x, y;
            cin >> n >> x >> y;

            string s;
            cin >> s;

            vector<long long> p(n);
            long long sumP = 0;
            for (int i = 0; i < n; i++) {
                cin >> p[i];
                sumP += p[i];
            }

            long long Amin = 0, Bmin = 0;
            for (int i = 0; i < n; i++) {
                long long need = p[i] / 2 + 1; // floor(p/2)+1
                if (s[i] == '0') Amin += need;
                else Bmin += need;
            }

            bool ok = true;
            if (x + y < sumP) ok = false;
            if (x < Amin) ok = false;
            if (y < Bmin) ok = false;

            cout << (ok ? "YES\n" : "NO\n");
        }
    }
};

int main() {
    BlackslexGirlsSolver solver;
    solver.solve();
    return 0;
}
