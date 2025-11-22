#include <bits/stdc++.h>
using namespace std;

class DifficultContestSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            string s;
            cin >> s;

            int cntT = 0, cntF = 0, cntN = 0;
            string others;

            for (char ch : s) {
                if (ch == 'T') cntT++;
                else if (ch == 'F') cntF++;
                else if (ch == 'N') cntN++;
                else others.push_back(ch);
            }

            string ans;

            ans.append(cntT, 'T');

            ans += others;

            ans.append(cntF, 'F');

            ans.append(cntN, 'N');

            cout << ans << "\n";
        }
    }
};

int main() {
    DifficultContestSolver solver;
    solver.solve();
    return 0;
}

