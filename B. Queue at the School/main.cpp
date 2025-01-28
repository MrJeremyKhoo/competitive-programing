#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;

    // Simulate the queue transformation for t seconds
    for (int time = 0; time < t; ++time) {
        for (int i = 0; i < n - 1; ++i) {
            // Swap 'B' and 'G' if 'B' is in front of 'G'
            if (s[i] == 'B' && s[i + 1] == 'G') {
                swap(s[i], s[i + 1]);
                ++i; // Skip the next position to avoid double-swapping
            }
        }
    }

    // Output the final arrangement
    cout << s << endl;

    return 0;
}

