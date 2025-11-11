#include <bits/stdc++.h>
using namespace std;

class Notelock {
public:
    int minProtections(int n, int k, const string& s) const {
        int groups = 0;
        int last = -1000000000;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (i - last >= k) {

                    ++groups;
                }
                last = i;
            }
        }
        return groups;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    Notelock solver;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        cout << solver.minProtections(n, k, s) << '\n';
    }
    return 0;
}

