#include <bits/stdc++.h>
using namespace std;

class PizzaTime {
public:
    long long maxHao(long long n) const {
        long long ans = 0;
        long long m = n;
        while (m > 2) {
            long long m1 = m / 3;
            ans += m1;
            m = m - 2 * m1;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    PizzaTime solver;
    while (t--) {
        long long n;
        cin >> n;
        cout << solver.maxHao(n) << '\n';
    }
    return 0;
}

