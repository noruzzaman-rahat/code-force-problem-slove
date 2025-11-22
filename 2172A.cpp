#include <bits/stdc++.h>
using namespace std;

int main() {
    int g, c, l;
    cin >> g >> c >> l;

    int mx = max({g, c, l});
    int mn = min({g, c, l});

    if (mx - mn >= 10) {
        cout << "check again\n";
    } else {
        vector<int> v = {g, c, l};
        sort(v.begin(), v.end());
        cout << "final " << v[1] << "\n";
    }

    return 0;
}

