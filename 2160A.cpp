#include <bits/stdc++.h>
using namespace std;

class MexPartition {
public:
    int solveOne(const vector<int>& A) const {


        const int LIM = 105;
        vector<bool> seen(LIM, false);
        for (int x : A) {
            if (0 <= x && x < LIM) seen[x] = true;
        }
        for (int m = 0; m < LIM; ++m) {
            if (!seen[m]) return m;
        }
        return LIM;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    MexPartition solver;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        cout << solver.solveOne(A) << '\n';
    }
    return 0;
}

