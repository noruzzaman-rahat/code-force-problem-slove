#include <bits/stdc++.h>
using namespace std;

class SquareChecker {
public:
    // Return true if a,b,c,d can form a square (all equal)
    bool isSquare(int a, int b, int c, int d) const {
        // Easiest: put them in a set and check if all equal
        // Or sort and check v[0] == v[3]
        int v[4] = {a, b, c, d};
        sort(v, v + 4);
        return v[0] == v[3];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    SquareChecker checker;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (checker.isSquare(a, b, c, d) ? "YES" : "NO") << '\n';
    }
    return 0;
}

