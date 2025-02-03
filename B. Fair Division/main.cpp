#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n, x;
    
    while(t--) {
      cin >> n;
      int count1 = 0, count2 = 0;
      for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
          count1++;
          continue;
        } 
        count2++;
      }
      if ((count2 % 2 == 1 && count1 == 0 ) || (count1 % 2 == 1 && count2 % 2 == 0) || (count2 % 2 == 1 && count1 % 2 == 1) ) {
        cout << "NO" << endl;
        continue;
      }
        cout << "YES" << endl; 
    }

    return 0;
}

