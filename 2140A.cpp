#include <bits/stdc++.h>
using namespace std;

class ShiftSort {
public:
    int minOperations(const string& s) const {
        int n = (int)s.size();
        int zeros = 0;
        for (char c : s) if (c == '0') ++zeros;

        // Count how many 1s are in the first 'zeros' positions
        int misplacedOnes = 0;
        for (int i = 0; i < zeros; ++i) {
            if (s[i] == '1') ++misplacedOnes;
        }
        return misplacedOnes;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    ShiftSort solver;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << solver.minOperations(s) << '\n';
    }
    return 0;
}
