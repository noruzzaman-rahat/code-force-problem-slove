#include <bits/stdc++.h>
using namespace std;

class Encoder {
private:
    int n;
    vector<int> a;

public:
    // Constructor to initialize with array data
    Encoder(int size, vector<int> arr) : n(size), a(arr) {}

    // Encode the array into a string
    string encode() {
        string result = "";

        // Encode each number as a letter (1->a, 2->b, ..., 26->z)
        // Use a delimiter 'z' + 'z' to separate numbers
        for (int i = 0; i < n; i++) {
            // Convert number to letter (1-indexed to 0-indexed)
            result += char('a' + a[i] - 1);

            // Add delimiter between numbers (except after last)
            if (i < n - 1) {
                result += "zz";
            }
        }

        return result;
    }
};

class Decoder {
private:
    string s;
    int n;
    vector<int> a;

public:
    // Constructor to initialize with encoded string
    Decoder(string encoded) : s(encoded), n(0) {}

    // Decode the string back to array
    void decode() {
        a.clear();

        // Split by delimiter "zz"
        int i = 0;
        while (i < s.length()) {
            // Check if we found a delimiter
            if (i + 1 < s.length() && s[i] == 'z' && s[i + 1] == 'z') {
                i += 2; // Skip the delimiter
                continue;
            }

            // Single character represents a number
            int num = s[i] - 'a' + 1;
            a.push_back(num);
            i++;
        }

        n = a.size();
    }

    // Get the decoded size
    int getSize() {
        return n;
    }

    // Get the decoded array
    vector<int> getArray() {
        return a;
    }

    // Print the result
    void printResult() {
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string phase;
    cin >> phase;

    if (phase == "first") {
        // Encoding phase
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Create encoder object and encode
        Encoder encoder(n, a);
        string encoded = encoder.encode();

        cout << encoded << endl;

    } else {
        // Decoding phase
        string s;
        cin >> s;

        // Create decoder object and decode
        Decoder decoder(s);
        decoder.decode();

        // Print the result
        decoder.printResult();
    }

    return 0;
}
