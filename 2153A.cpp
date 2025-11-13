#include <bits/stdc++.h>
using namespace std;

class CircleOfAppleTrees {
public:
    int maxApples(const vector<int>& b) const {
        unordered_set<int> uniq(b.begin(), b.end());
        return (int)uniq.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    CircleOfAppleTrees solver;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];
        cout << solver.maxApples(b) << '\n';
    }
    return 0;
}

