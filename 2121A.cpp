#include <bits/stdc++.h>
using namespace std;

class LetterHomeSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n, s;
            cin >> n >> s;
            vector<int> x(n);
            for (int i = 0; i < n; ++i) {
                cin >> x[i];
            }

            int L = x.front();
            int R = x.back();

            int ans = (R - L) + min(abs(s - L), abs(s - R));
            cout << ans << "\n";
        }
    }
};

int main() {
    LetterHomeSolver solver;
    solver.solve();
    return 0;
}

