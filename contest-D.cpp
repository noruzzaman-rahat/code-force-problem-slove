#include <bits/stdc++.h>
using namespace std;

class PenguinCivilizationSolver {
public:
    vector<int> build(int n) {
        int N = 1 << n;
        vector<char> used(N, 0);
        vector<int> ans;
        ans.reserve(N);

        int M = N - 1;

        auto emit_supersets_increasing = [&](int mask) {

            vector<int> zeros;
            zeros.reserve(n);
            for (int b = 0; b < n; b++) {
                if (((mask >> b) & 1) == 0) zeros.push_back(b);
            }
            int z = (int)zeros.size();
            int lim = 1 << z;

            for (int add = 0; add < lim; add++) {
                int v = mask;
                for (int j = 0; j < z; j++) {
                    if (add & (1 << j)) v |= (1 << zeros[j]);
                }
                if (!used[v]) {
                    used[v] = 1;
                    ans.push_back(v);
                }
            }
        };

        while ((int)ans.size() < N) {
            emit_supersets_increasing(M);
            if ((int)ans.size() == N) break;
            if (M == 0) break;


            int hb = 31 - __builtin_clz(M);
            M ^= (1 << hb);
        }


        for (int v = 0; v < N; v++) {
            if (!used[v]) ans.push_back(v);
        }
        return ans;
    }

    void run() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            auto p = build(n);
            for (int i = 0; i < (int)p.size(); i++) {
                cout << p[i] << (i + 1 == (int)p.size() ? '\n' : ' ');
            }
        }
    }
};

int main() {
    PenguinCivilizationSolver solver;
    solver.run();
    return 0;
}

