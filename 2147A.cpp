#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        if (y == x) {
            cout << -1 << '\n';
        } else if (y > x) {
            cout << 2 << '\n';
        } else { // x > y
            if (y == 1 || x - y == 1) cout << -1 << '\n';
            else cout << 3 << '\n';
        }
    }
    return 0;
}

