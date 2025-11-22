#include <bits/stdc++.h>
using namespace std;

class Painter {
public:
    bool isSymmetric(long long n, long long a, long long b) {
        // Blue must be placeable symmetrically
        if ((n - b) % 2 != 0) return false;

        if (a <= b) return true;             // Red can be fully hidden inside blue
        if ((a - b) % 2 == 0) return true;   // Red sticks out symmetrically

        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    Painter solver;

    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        cout << (solver.isSymmetric(n, a, b) ? "YES" : "NO") << "\n";
    }

    return 0;
}

