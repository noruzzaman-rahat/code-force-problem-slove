#include <bits/stdc++.h>
using namespace std;

class NumberTheorySolver {
public:
    long long solveCase(const vector<long long>& a) {
        long long mn = LLONG_MAX, mn2 = LLONG_MAX;
        for (long long v : a) {
            if (v < mn) {
                mn2 = mn;
                mn = v;
            } else if (v < mn2) {
                mn2 = v;
            }
        }
        long long d = mn2 - mn;
        return max(mn, d);
    }

    void run() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<long long> a(n);
            for (int i = 0; i < n; i++) cin >> a[i];
            cout << solveCase(a) << "\n";
        }
    }
};

int main() {
    NumberTheorySolver solver;
    solver.run();
    return 0;
}
