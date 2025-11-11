#include <bits/stdc++.h>
using namespace std;

class GameSolver {
public:
    string canForceWin(vector<int> a) const {
        sort(a.begin(), a.end());
        for (int i = 1; i + 1 < (int)a.size(); i += 2) {
            if (a[i] != a[i + 1]) return "NO";
        }
        return "YES";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    GameSolver solver;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solver.canForceWin(a) << '\n';
    }
    return 0;
}

