#include <bits/stdc++.h>
using namespace std;

class MadHackSolver {
public:
    void run() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        if (!(cin >> t)) return;
        while (t--) {
            int n;
            cin >> n;
            vector<int> a(2 * n);
            for (int i = 0; i < 2 * n; ++i) cin >> a[i];


            cout << "! ";
            for (int i = 0; i < 2 * n; ++i) {
                if (i) cout << ' ';
                cout << a[i];
            }
            cout << '\n';
        }
    }
};

int main() {
    MadHackSolver solver;
    solver.run();
    return 0;
}
