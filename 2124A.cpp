#include <bits/stdc++.h>
using namespace std;

class DerangedDeletionsSolver {
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

            bool found = false;
            int pos1 = -1, pos2 = -1;


            for (int i = 0; i < n && !found; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (a[i] > a[j]) {
                        found = true;
                        pos1 = i;
                        pos2 = j;
                        break;
                    }
                }
            }

            if (!found) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                cout << 2 << "\n";
                cout << a[pos1] << " " << a[pos2] << "\n";
            }
        }
    }
};

int main() {
    DerangedDeletionsSolver solver;
    solver.solve();
    return 0;
}

