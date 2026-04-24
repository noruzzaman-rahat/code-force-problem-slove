#include <bits/stdc++.h>
using namespace std;

int mygcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

class LRCAndVIPSolver {
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


            bool allEqual = true;
            for (int i = 1; i < n; ++i) {
                if (a[i] != a[0]) {
                    allEqual = false;
                    break;
                }
            }

            if (allEqual) {
                cout << "No\n";
                continue;
            }


            int idx = -1;
            for (int i = 0; i < n; ++i) {
                int g = 0;
                for (int j = 0; j < n; ++j) {
                    if (j == i) continue;
                    g = mygcd(g, a[j]);
                }
                if (g != a[i]) {
                    idx = i;
                    break;
                }
            }

            cout << "Yes\n";
            for (int i = 0; i < n; ++i) {
                if (i == idx) cout << 1;
                else          cout << 2;
                if (i + 1 < n) cout << ' ';
            }
            cout << "\n";
        }
    }
};

int main() {
    LRCAndVIPSolver solver;
    solver.solve();
    return 0;
}
