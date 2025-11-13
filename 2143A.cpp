#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        int pos = -1;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            if (p[i] == n) pos = i;
        }

        bool ok = (pos != -1);

        for (int i = 1; i < pos && ok; ++i) {
            if (!(p[i] < p[i + 1])) ok = false;
        }

        for (int i = pos + 1; i <= n && ok; ++i) {
            if (!(p[i] < p[i - 1])) ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}

