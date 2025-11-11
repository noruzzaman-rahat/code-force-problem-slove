#include <bits/stdc++.h>
using namespace std;

class BeautifulAverage {
public:
    int solveOne(const vector<int>& a) const {
        return *max_element(a.begin(), a.end());
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    BeautifulAverage solver;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solver.solveOne(a) << '\n';
    }
    return 0;
}

