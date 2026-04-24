#include <bits/stdc++.h>
using namespace std;

class BlackslexPlantsSolver {
private:
    struct Buckets {
        int p;
        vector<long long> cnt;
        vector<long long> sum;
        Buckets(int p=1): p(p), cnt(p,0), sum(p,0) {}
        inline void add(int x, int delta) {
            int r = x % p;
            cnt[r] += delta;
            sum[r] += 1LL * delta * x;
        }
        inline long long Ak(long long t) const {
            int r = (int)(t % p);
            return cnt[r] * t - sum[r];
        }
    };

public:
    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int T;
        cin >> T;
        while (T--) {
            int n, q;
            cin >> n >> q;

            vector<vector<int>> addAt(n + 2), remAt(n + 2);
            for (int _ = 0; _ < q; _++) {
                int l, r;
                cin >> l >> r;
                addAt[l].push_back(l);
                if (r + 1 <= n + 1) remAt[r + 1].push_back(l);
            }


            vector<Buckets> B;
            for (int p = 1; p <= n + 1; p <<= 1) B.emplace_back(p);

            vector<long long> ans(n + 1, 0);

            for (int i = 1; i <= n; i++) {

                for (int l : addAt[i]) {
                    for (auto &bk : B) bk.add(l, +1);
                }

                for (int l : remAt[i]) {
                    for (auto &bk : B) bk.add(l, -1);
                }

                long long t = i + 1LL;


                long long cur = 0;

                cur += B[0].Ak(t);


                for (int k = 1; k < (int)B.size(); k++) {
                    long long Ak = B[k].Ak(t);
                    cur += (1LL << (k - 1)) * Ak;
                }

                ans[i] = cur;
            }

            for (int i = 1; i <= n; i++) {
                cout << ans[i] << (i == n ? '\n' : ' ');
            }
        }
    }
};

int main() {
    BlackslexPlantsSolver solver;
    solver.solve();
    return 0;
}

