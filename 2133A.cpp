#include <bits/stdc++.h>
using namespace std;

class Redstone {
public:
    bool canArrange(const vector<int>& gears) {
        unordered_set<int> seen;
        for (int x : gears) {
            if (seen.count(x)) return true;  // duplicate exists
            seen.insert(x);
        }
        return false; // all distinct
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    Redstone solver;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        cout << (solver.canArrange(a) ? "YES" : "NO") << "\n";
    }

    return 0;
}

