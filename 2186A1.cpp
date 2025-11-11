#include <bits/stdc++.h>
using namespace std;

class EncoderDecoder {
public:
    // Encodes the array a into a lowercase string s
    string encode(const vector<int>& a) {
        string s;
        s.reserve(a.size());
        for (int x : a) {
            // x is in [1, 26] per easy version constraints
            s.push_back(char('a' + (x - 1)));
        }
        return s;
    }

    // Decodes the lowercase string s back into the original array a
    vector<int> decode(const string& s) {
        vector<int> a;
        a.reserve(s.size());
        for (char c : s) {
            // c is lowercase letter
            a.push_back(int(c - 'a') + 1);
        }
        return a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string phase;
    if (!(cin >> phase)) return 0;

    EncoderDecoder ed;

    if (phase == "first") {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // Encode and output the string s (lowercase only, no spaces)
        string s = ed.encode(a);
        cout << s << '\n';
    } else if (phase == "second") {
        string s;
        cin >> s;

        // Decode and output: n and the array
        vector<int> a = ed.decode(s);
        cout << (int)a.size();
        for (int x : a) cout << ' ' << x;
        cout << '\n';
    }

    return 0;
}

