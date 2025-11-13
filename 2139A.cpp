#include <bits/stdc++.h>
using namespace std;

class MapleAndMultiplication {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            long long a, b;
            cin >> a >> b;
            cout << minOperations(a, b) << '\n';
        }
    }

private:
    int minOperations(long long a, long long b) {
        if (a == b) return 0;

        long long mx = max(a, b);
        long long mn = min(a, b);

        if (mx % mn == 0) return 1;

        return 2;
    }
};

int main() {
    MapleAndMultiplication solver;
    solver.solve();
    return 0;
}

