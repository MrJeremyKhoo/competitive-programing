#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  
  int total = 0;
  for (int i = 0; i < n - 1; ++i) {
    if(s[i] == s[i + 1]) {
      total++;
    }  
  }
  cout << total << endl;
  return 0;
}
