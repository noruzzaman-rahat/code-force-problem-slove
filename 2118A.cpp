#include <bits/stdc++.h>
using namespace std;

class EqualSubsequencesSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n, k;
            cin >> n >> k;

            string s;
            s.append(k, '1');
            s.append(n - k, '0');

            cout << s << "\n";
        }
    }
};

int main() {
    EqualSubsequencesSolver solver;
    solver.solve();
    return 0;
}

