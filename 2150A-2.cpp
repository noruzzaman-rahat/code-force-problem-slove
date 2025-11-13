#include <bits/stdc++.h>
using namespace std;

struct Intervals {
    // disjoint merged intervals of black cells: map<L, R>
    map<long long, long long> seg;

    // build from sorted distinct points
    void build_from_points(const vector<long long>& a) {
        for (int i = 0; i < (int)a.size();) {
            long long L = a[i], R = a[i];
            int j = i + 1;
            while (j < (int)a.size() && a[j] == R + 1) { R = a[j]; ++j; }
            seg[L] = R;
            i = j;
        }
    }

    // next white cell strictly greater than x  (i.e., min y > x that's white)
    long long next_white_after(long long x) const {
        long long y = x + 1;
        auto it = seg.upper_bound(y);
        if (it != seg.begin()) {
            auto p = prev(it);
            if (p->first <= y && y <= p->second) return p->second + 1;
        }
        return y;
    }

    // add single black point p, merging neighbors; idempotent
    void add_point(long long p) {
        auto it = seg.upper_bound(p);
        long long L = p, R = p;

        // inside existing -> already black
        if (it != seg.begin()) {
            auto pIt = prev(it);
            if (pIt->first <= p && p <= pIt->second) return;
            if (pIt->second + 1 == p) { // merge left
                L = pIt->first;
                seg.erase(pIt);
            }
        }
        // merge right if adjacent
        if (it != seg.end() && it->first == p + 1) {
            R = it->second;
            seg.erase(it);
        }
        seg[L] = max(L, R);
    }

    // dump all black cells
    void print_all() const {
        for (auto &kv : seg) {
            for (long long x = kv.first; x <= kv.second; ++x) cout << x << ' ';
        }
        cout << '\n';
    }
    long long count_all() const {
        long long tot = 0;
        for (auto &kv : seg) tot += (kv.second - kv.first + 1);
        return tot;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<long long> a(m);
        for (int i = 0; i < m; ++i) cin >> a[i];

        Intervals S;
        S.build_from_points(a); // initial black cells (a is strictly increasing)

        long long last = 0; // "previous cell"; before first move we consider last=0 so A/B use last+1 correctly
        for (int i = 0; i < n; ++i) {
            long long cur;
            if (s[i] == 'A') {
                cur = last + 1;
            } else { // 'B'
                cur = S.next_white_after(last);
            }
            S.add_point(cur);
            last = cur;
        }

        cout << S.count_all() << '\n';
        S.print_all();
    }
    return 0;
}

