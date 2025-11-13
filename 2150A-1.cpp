#include <bits/stdc++.h>
using namespace std;

class IncrementalPathFastest {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n, m;
            cin >> n >> m;
            string s;
            cin >> s;
            vector<long long> a(m);
            for (int i = 0; i < m; ++i) cin >> a[i];

            // keep all black cells sorted
            set<long long> black(a.begin(), a.end());

            long long cur = 1;
            for (char c : s) {
                if (c == 'A') {
                    cur++;
                } else { // 'B' = jump to next white
                    auto it = black.lower_bound(cur + 1);
                    if (it != black.end() && *it == cur + 1) {
                        // skip contiguous black block
                        while (it != black.end() && *it == cur + 1) {
                            cur = *it;
                            ++it;
                        }
                        ++cur; // jump past black block
                    } else {
                        ++cur;
                    }
                }
                black.insert(cur); // paint cell black
            }

            cout << black.size() << '\n';
            for (auto x : black) cout << x << ' ';
            cout << '\n';
        }
    }
};

int main() {
    IncrementalPathFastest().solve();
    return 0;
}

