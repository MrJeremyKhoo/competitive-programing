#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;  // Max size for Fenwick Tree

// Fenwick Tree (Binary Indexed Tree) Implementation
struct FenwickTree {
    vector<int> BIT;
    int size;

    FenwickTree(int n) : size(n) { BIT.assign(n + 1, 0); }

    void update(int index, int val) {
        while (index <= size) {
            BIT[index] += val;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), compressed(n);

    // Read input
    for (int i = 0; i < n; i++) cin >> a[i];

    // Coordinate Compression (map values to range [1, n])
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    for (int i = 0; i < n; i++) {
        compressed[i] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin() + 1;
    }

    // Compute left_count using a Fenwick Tree
    FenwickTree leftTree(n);
    vector<int> left_count(n, 0);
    for (int i = 0; i < n; i++) {
        left_count[i] = leftTree.query(n) - leftTree.query(compressed[i]); // Count greater elements to the left
        leftTree.update(compressed[i], 1);
    }

    // Compute right_count using another Fenwick Tree
    FenwickTree rightTree(n);
    vector<int> right_count(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        right_count[i] = rightTree.query(compressed[i] - 1); // Count smaller elements to the right
        rightTree.update(compressed[i], 1);
    }

    // Calculate the final result
    long long weakness = 0;
    for (int j = 0; j < n; j++) {
        weakness += 1LL * left_count[j] * right_count[j];
    }

    cout << weakness << "\n";
    return 0;
}

