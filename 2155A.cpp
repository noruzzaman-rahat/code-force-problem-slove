#include <bits/stdc++.h>
using namespace std;

class ElFucho {
public:
    int totalMatches(int n) const {
        return 2 * n - 2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    ElFucho solver;
    while (t--) {
        int n;
        cin >> n;
        cout << solver.totalMatches(n) << '\n';
    }
    return 0;
}

