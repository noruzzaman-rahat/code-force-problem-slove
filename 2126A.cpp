#include <bits/stdc++.h>
using namespace std;

class OnlyOneDigitSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            string x;
            cin >> x;

            char mn = '9';
            for (char ch : x) {
                if (ch < mn) mn = ch;
            }


            cout << (mn - '0') << "\n";
        }
    }
};

int main() {
    OnlyOneDigitSolver solver;
    solver.solve();
    return 0;
}

