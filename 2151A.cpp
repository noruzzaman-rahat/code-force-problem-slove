#include <bits/stdc++.h>
using namespace std;

class IncrementalSubarray {
public:
    long long countOccurrences(long long n, const vector<int>& a) const {
        int m = (int)a.size();

        vector<int> seg;
        int L = 1;
        for (int i = 0; i + 1 < m; ++i) {
            if (a[i+1] == a[i] + 1) {
                ++L;
            } else if (a[i+1] == 1) {
                seg.push_back(L);
                L = 1;
            } else {
                return 0;
            }
        }
        seg.push_back(L);
        int r = (int)seg.size();
        int v = a[0];

        if (r == 1) {
            long long Tmin = v + seg[0] - 1;
            if (Tmin > n) return 0;
            return n - Tmin + 1;
        } else {
            long long T = v + seg[0] - 1;
            if (T < 1) return 0;

            for (int j = 2; j <= r-1; ++j) {
                long long need = T + (j-1);
                if (seg[j-1] != need) return 0;
                if (need > n) return 0;
            }

            long long lastBlock = T + (r-1);
            if (lastBlock > n) return 0;
            if (seg[r-1] > lastBlock) return 0;

            return 1;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    IncrementalSubarray solver;

    while (t--) {
        long long n; int m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) cin >> a[i];
        cout << solver.countOccurrences(n, a) << '\n';
    }
    return 0;
}
