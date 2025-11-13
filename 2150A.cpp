#include <bits/stdc++.h>
using namespace std;



struct NextWhite {
    unordered_map<long long, long long> parent;
    unordered_set<long long> black;


    long long get(long long y) {

        if (!black.count(y)) return y;

        auto it = parent.find(y);
        if (it == parent.end()) {

            long long nxt = get(y + 1);
            parent[y] = nxt;
            return nxt;
        } else {
            long long nxt = get(it->second);
            parent[y] = nxt;
            return nxt;
        }
    }


    void paint(long long x) {
        if (black.insert(x).second) {

            parent[x] = get(x + 1);
        }

    }
};

class IncrementalPath {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        if (!(cin >> T)) return;
        while (T--) {
            int n, m;
            cin >> n >> m;
            string s;
            cin >> s;
            vector<long long> a(m);
            for (int i = 0; i < m; ++i) cin >> a[i];

            NextWhite DSU;


            for (long long x : a) DSU.paint(x);

            vector<long long> painted; painted.reserve(n + m);


            for (int i = 0; i < n; ++i) {
                long long cur = 1;

                for (int j = 0; j <= i; ++j) {
                    if (s[j] == 'A') {
                        cur += 1;
                    } else { // 'B'
                        cur = DSU.get(cur + 1);
                    }
                }


                DSU.paint(cur);
            }


            vector<long long> res;
            res.reserve(DSU.black.size());
            for (auto x : DSU.black) res.push_back(x);
            sort(res.begin(), res.end());

            cout << res.size() << '\n';
            for (auto x : res) cout << x << ' ';
            cout << '\n';
        }
    }
};

int main() {
    IncrementalPath().solve();
    return 0;
}
