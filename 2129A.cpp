#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find) structure
class DSU {
private:
    vector<int> parent, sz;
public:
    DSU(int n = 0) { init(n); }

    void init(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    // returns true if union happened (different components)
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

// Solver class for the whole problem
class DoublePerspectiveSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            vector<pair<int,int>> seg(n);
            for (int i = 0; i < n; ++i) {
                cin >> seg[i].first >> seg[i].second;
            }

            // Max coordinate is at most 2n (given in statement)
            int maxC = 2 * n;

            // Step 1: build coverage array with diff
            vector<int> diff(maxC + 3, 0);
            for (int i = 0; i < n; ++i) {
                int a = seg[i].first;
                int b = seg[i].second;
                diff[a] += 1;
                diff[b] -= 1;
            }

            vector<int> cov(maxC + 3, 0);
            int cur = 0;
            for (int x = 1; x <= maxC; ++x) {
                cur += diff[x];
                cov[x] = cur; // cov[x] = coverage of segment [x, x+1]
            }

            // Step 2: determine which edges are "safe to remove"
            // safe[i] = true -> removing this edge does NOT decrease f
            vector<bool> safe(n, false);
            for (int i = 0; i < n; ++i) {
                int a = seg[i].first;
                int b = seg[i].second;
                bool ok = true;
                // Check all x in [a, b-1], i.e. segments [x, x+1]
                for (int x = a; x < b; ++x) {
                    if (cov[x] < 2) {
                        ok = false;
                        break;
                    }
                }
                safe[i] = ok;
            }

            // Step 3: build forest using DSU
            DSU dsu(maxC);
            vector<int> chosen;  // store indices of selected intervals (0-based)

            // 3a) Add all UNSAFE edges first (they must stay to keep f maximal)
            for (int i = 0; i < n; ++i) {
                if (!safe[i]) {
                    int a = seg[i].first;
                    int b = seg[i].second;
                    chosen.push_back(i);
                    dsu.unite(a, b);  // always unite, they theoretically won't form a cycle among themselves
                }
            }

            // 3b) Add SAFE edges only if they don't create cycles
            for (int i = 0; i < n; ++i) {
                if (safe[i]) {
                    int a = seg[i].first;
                    int b = seg[i].second;
                    if (dsu.unite(a, b)) {
                        // they were in different components, so no cycle; we can add this edge
                        chosen.push_back(i);
                    }
                    // else, adding would create a cycle; skip this safe edge
                }
            }

            // Step 4: output result (1-based indices)
            cout << chosen.size() << "\n";
            if (!chosen.empty()) {
                for (int i = 0; i < (int)chosen.size(); ++i) {
                    if (i) cout << ' ';
                    cout << (chosen[i] + 1);
                }
                cout << "\n";
            } else {

                cout << "\n";
            }
        }
    }
};

int main() {
    DoublePerspectiveSolver solver;
    solver.solve();
    return 0;
}

