#include <bits/stdc++.h>
using namespace std;

class SubmissionSolver {
private:
    int n;
    vector<int> S;
public:
    SubmissionSolver(int n, const vector<int>& S) : n(n), S(S) {}

    long long solve() {
        const int MAXV = 1005; // generous upper bound for values (safe)
        vector<int> cnt(MAXV, 0);
        long long sumS = 0;
        int maxVal = 0;
        for (int x : S) {
            if (x >= 0 && x < MAXV) cnt[x]++;
            sumS += x;
            maxVal = max(maxVal, x);
        }

        long long ans = sumS; // case: only use sum-operations

        // try every possible mex k (k from 0..maxVal+1 is enough, but we use MAXV small loop)
        for (int k = 0; k <= maxVal + 1 && k < MAXV; ++k) {
            bool ok = true;
            for (int i = 0; i < k; ++i) {
                if (cnt[i] == 0) { ok = false; break; }
            }
            if (!ok) continue; // if k not feasible, try next k (defensive; break would also be correct)
            long long removed_sum = 1LL * k * (k - 1) / 2;
            long long candidate = sumS - removed_sum + k;
            ans = max(ans, candidate);
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> S(n);
        for (int i = 0; i < n; ++i) cin >> S[i];

        SubmissionSolver solver(n, S);
        cout << solver.solve() << '\n';
    }
    return 0;
}
