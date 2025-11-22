#include <bits/stdc++.h>
using namespace std;

class SquareYearSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            string s;
            cin >> s;

            int year = stoi(s);

            int c = (int) floor(sqrt(year));
            if (1LL * c * c == year) {

                cout << 0 << " " << c << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
};

int main() {
    SquareYearSolver solver;
    solver.solve();
    return 0;
}

