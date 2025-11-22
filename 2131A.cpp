#include <iostream>
#include <vector>
using namespace std;

class Lever {
private:
    int n;
    vector<int> a, b;

public:
    Lever(int n, vector<int> a, vector<int> b)
        : n(n), a(a), b(b) {}

    int solve() {
        int excess = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                excess += (a[i] - b[i]);
            }
        }

        return excess + 1; // final iteration where step 1 fails is counted
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        Lever solver(n, a, b);
        cout << solver.solve() << "\n";
    }

    return 0;
}

