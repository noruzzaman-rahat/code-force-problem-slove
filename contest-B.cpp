#include <bits/stdc++.h>
using namespace std;

class ShoweringSolver {
public:
    long long solveCase(const vector<int>& a) {
        int n = (int)a.size();
        long long S = 0;
        for (int i = 0; i < n - 1; i++) {
            S += llabs(a[i] - a[i + 1]);
        }

        long long ans = S;


        ans = min(ans, S - llabs(a[0] - a[1]));

        ans = min(ans, S - llabs(a[n - 2] - a[n - 1]));


        for (int k = 1; k <= n - 2; k++) {
            long long left = llabs(a[k - 1] - a[k]);
            long long right = llabs(a[k] - a[k + 1]);
            long long bridge = llabs(a[k - 1] - a[k + 1]);
            long long cur = S - left - right + bridge;
            ans = min(ans, cur);
        }

        return ans;
    }

    void run() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; i++) cin >> a[i];
            cout << solveCase(a) << "\n";
        }
    }
};

int main() {
    ShoweringSolver solver;
    solver.run();
    return 0;
}

