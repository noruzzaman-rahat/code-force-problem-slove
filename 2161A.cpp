#include <bits/stdc++.h>
using namespace std;

class RoundTrip {
public:
    long long solveOne(long long R0, long long X, long long D, int n, const string& s) const {
        long long R = R0;
        long long rated = 0;

        for (int i = 0; i < n; ++i) {
            char type = s[i];

            if (type == '1') {

                rated++;
                stepRated(R, X, D);
            } else {
                if (R < X) {

                    rated++;
                    stepRated(R, X, D);
                }

            }
        }
        return rated;
    }

private:
    static inline void stepRated(long long& R, long long X, long long D) {
        long long lb = max(0LL, R - D);
        long long ub = R + D;


        long long targetBelowX = X - 1;
        if (lb <= targetBelowX) {

            R = min(ub, targetBelowX);
        } else {

            R = lb;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    RoundTrip solver;
    while (t--) {
        long long R0, X, D;
        int n;
        cin >> R0 >> X >> D >> n;
        string s;
        cin >> s;

        cout << solver.solveOne(R0, X, D, n, s) << '\n';
    }
    return 0;
}

