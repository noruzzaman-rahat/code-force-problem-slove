#include <bits/stdc++.h>
using namespace std;

class SequenceGame {
public:
    // returns "YES" if x can be the final number, otherwise "NO"
    string canBe(long long x, const vector<long long>& a) const {
        long long mn = *min_element(a.begin(), a.end());
        long long mx = *max_element(a.begin(), a.end());
        return (mn <= x && x <= mx) ? "YES" : "NO";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    SequenceGame solver;

    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        long long x;
        cin >> x;

        cout << solver.canBe(x, a) << '\n';
    }
    return 0;
}

