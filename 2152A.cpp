#include <bits/stdc++.h>
using namespace std;

class IncreaseOrSmash {
public:
    int minOperations(const vector<int>& a) const {
        unordered_set<int> s(a.begin(), a.end());
        int m = (int)s.size();
        return 2 * m - 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    IncreaseOrSmash solver;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solver.minOperations(a) << '\n';
    }
    return 0;
}

