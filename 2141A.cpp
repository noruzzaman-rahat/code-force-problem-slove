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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<int> neverOrdered;
        int prefMin = INT_MAX;

        for (int i = 1; i <= n; ++i) {
            if (a[i] < prefMin) {
                prefMin = a[i];
            } else {
                neverOrdered.push_back(i);
            }
        }

        cout << (int)neverOrdered.size() << '\n';
        if (!neverOrdered.empty()) {
            for (int i = 0; i < (int)neverOrdered.size(); ++i) {
                if (i) cout << ' ';
                cout << neverOrdered[i];
            }
            cout << '\n';
        } else {
            cout << '\n';
        }
    }
    return 0;
}

