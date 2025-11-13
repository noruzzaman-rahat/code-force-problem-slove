#include <bits/stdc++.h>
using namespace std;

class BePositive {
public:
    int minOps(const vector<int>& a) const {
        int zeros = 0, negs = 0;
        for (int x : a) {
            if (x == 0) ++zeros;
            else if (x == -1) ++negs;
        }
        return zeros + ((negs % 2) ? 2 : 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    BePositive solver;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solver.minOps(a) << '\n';
    }
    return 0;
}

