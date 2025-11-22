#include <bits/stdc++.h>
using namespace std;

class AliceAndBobSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        const long long B_MIN = 0;
        const long long B_MAX = 2000000000LL;

        while (T--) {
            int n;
            long long a;
            cin >> n >> a;
            vector<long long> v(n);
            for (int i = 0; i < n; ++i) {
                cin >> v[i];
            }

            vector<pair<long long, int>> events; // (position, delta)

            for (int i = 0; i < n; ++i) {
                long long val = v[i];
                long long D = llabs(val - a);
                if (D == 0) {
                    // Bob can never win this marble
                    continue;
                }
                long long L = val - D + 1;
                long long R = val + D - 1;

                // intersect with [B_MIN, B_MAX]
                if (L < B_MIN) L = B_MIN;
                if (R > B_MAX) R = B_MAX;
                if (L > R) continue; // no integer b in allowed range

                events.push_back({L, +1});
                if (R < B_MAX) {
                    events.push_back({R + 1, -1});
                }
                // if R == B_MAX, we don't need the R+1 event since that's beyond domain
            }

            if (events.empty()) {
                // Bob never wins any marble – any b is fine
                cout << 0 << "\n";
                continue;
            }

            sort(events.begin(), events.end());

            long long cur = 0;
            long long bestScore = 0;
            long long bestB = 0;

            // Current index in events
            for (size_t i = 0; i < events.size(); ) {
                long long x = events[i].first;

                // Apply all events at this position
                while (i < events.size() && events[i].first == x) {
                    cur += events[i].second;
                    ++i;
                }

                if (x >= B_MIN && x <= B_MAX && cur > bestScore) {
                    bestScore = cur;
                    bestB = x;
                }
            }

            cout << bestB << "\n";
        }
    }
};

int main() {
    AliceAndBobSolver solver;
    solver.solve();
    return 0;
}

