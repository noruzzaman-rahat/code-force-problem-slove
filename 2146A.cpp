#include <bits/stdc++.h>
using namespace std;

class EqualOccurrences {
public:
    int longestBalanced(const vector<int>& a) const {
        vector<int> cnt;

        for (int i = 0; i < (int)a.size(); ) {
            int j = i;
            while (j < (int)a.size() && a[j] == a[i]) ++j;
            cnt.push_back(j - i);
            i = j;
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        int best = 0;
        for (int f = 1; f <= mx; ++f) {
            int have = 0;
            for (int c : cnt) if (c >= f) ++have;
            best = max(best, f * have);
        }
        return best;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    EqualOccurrences solver;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solver.longestBalanced(a) << '\n';
    }
    return 0;
}

