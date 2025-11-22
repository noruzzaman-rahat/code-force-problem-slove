#include <bits/stdc++.h>
using namespace std;

class RecyclingCenterSolver {
public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n;
            long long c;
            cin >> n >> c;
            vector<long long> a(n);
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }


            sort(a.begin(), a.end());



            vector<long long> threshold(n);
            for (int i = 0; i < n; ++i) {

                threshold[i] = c >> i;


            }


            sort(threshold.begin(), threshold.end());


            int i = 0;
            int j = 0;
            int freeCount = 0;

            while (i < n && j < n) {
                if (a[i] <= threshold[j]) {

                    ++freeCount;
                    ++i;
                    ++j;
                } else {

                    ++j;
                }
            }

            int coins = n - freeCount;
            cout << coins << "\n";
        }
    }
};

int main() {
    RecyclingCenterSolver solver;
    solver.solve();
    return 0;
}

