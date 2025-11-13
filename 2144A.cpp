#include <bits/stdc++.h>
using namespace std;

static inline int mod3(long long x) { x %= 3; if (x < 0) x += 3; return (int)x; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];


        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            pref[i] = mod3(pref[i - 1] + a[i - 1]);
        int total = pref[n];

        pair<int,int> ans = {0, 0};


        auto try_all_equal = [&]() -> bool {
            for (int l = 1; l <= n - 2; ++l) {
                for (int r = l + 1; r <= n - 1; ++r) {
                    int s1 = pref[l];
                    int s2 = mod3(pref[r] - pref[l]);
                    int s3 = mod3(total - pref[r]);
                    if (s1 == s2 && s2 == s3) { ans = {l, r}; return true; }
                }
            }
            return false;
        };

        auto try_all_diff = [&]() -> bool {
            for (int l = 1; l <= n - 2; ++l) {
                for (int r = l + 1; r <= n - 1; ++r) {
                    int s1 = pref[l];
                    int s2 = mod3(pref[r] - pref[l]);
                    int s3 = mod3(total - pref[r]);
                    if (s1 != s2 && s1 != s3 && s2 != s3) { ans = {l, r}; return true; }
                }
            }
            return false;
        };

        if (!try_all_equal()) try_all_diff();
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}
