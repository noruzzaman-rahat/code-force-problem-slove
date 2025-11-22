#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TestCase class to handle the problem logic
class TestCase {
private:
    string a;  // Initial string a
    string b;  // String b with characters to add
    string c;  // String c with distribution of characters (V for Vlad, D for Dima)

public:
    // Constructor to initialize the values
    TestCase(string a, string b, string c) : a(a), b(b), c(c) {}

    // Function to solve the current test case
    string solve() {
        // Convert a string into a mutable string (for easier manipulation)
        string result = a;

        // Process each character of b and add to result based on who is adding
        for (int i = 0; i < b.length(); i++) {
            if (c[i] == 'V') {
                // Vlad adds to the beginning
                result = b[i] + result;
            } else {
                // Dima adds to the end
                result += b[i];
            }
        }

        return result;
    }
};

int main() {
    int t;  // Number of test cases
    cin >> t;

    while (t--) {
        int n, m;
        string a, b, c;

        // Read the input for each test case
        cin >> n;
        cin >> a;
        cin >> m;
        cin >> b;
        cin >> c;

        // Create an object of the TestCase class
        TestCase testCase(a, b, c);

        // Output the result for the current test case
        cout << testCase.solve() << endl;
    }

    return 0;
}

