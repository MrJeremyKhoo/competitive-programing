#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

struct FenwickTree {
  vector<int> BIT;
  int size;
  
  FenwickTree(int n) : size(n) { BIT.assign(n+1,0); }
  
  void update(int index, int val) {
    while(index <= size) {
      BIT[index] += val;
      index += index & -index;
    }
  }
  
  int query(int index) {
    int sum = 0;
    while(index > 0) {
      sum += BIT[index];
      index -= index & -index;   
    }
    return sum;
  }
};

vector<int> compression(vector<int> raw, int length) {
  vector<int> sorted_a = raw;
  vector<int> compressed(length);

  sort(sorted_a.begin(), sorted_a.end());
  
  for (int i = 0; i < length; i++) {
    compressed[i] = lower_bound(sorted_a.begin(), sorted_a.end(), raw[i]) - sorted_a.begin() + 1;
  
  }
  return compressed;

};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);

  for (int i =0; i < n; i++) cin >>a[i];
  
  vector<int> compressed = compression(a, n);

  //Left counting
  FenwickTree leftTree(n);
  vector<int> left_count(n,0);
  for(int i =0; i < n; i++) {
    left_count[i] = leftTree.query(n) - leftTree.query(compressed[i]); 
    leftTree.update(compressed[i],1);
  }

  //Right counting
  FenwickTree rightTree(n);
  vector<int> right_count(n,0);
  for(int i = n -1; i >= 0; i--) {
    right_count[i] = rightTree.query(compressed[i] - 1);
    rightTree.update(compressed[i],1);
  }
  
  long long weakness = 0;
  for (int j = 0; j < n; j++) {
    weakness += 1LL * left_count[j] * right_count[j];
  }
  
  cout << weakness << "\n";
  return 0;
  
}
    
