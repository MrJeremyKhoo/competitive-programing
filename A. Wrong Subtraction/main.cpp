#include <iostream>

using namespace std;

int main() {
  int n, k, tmp; 
  cin >> n >> k;

  while (k > 0)  {
    tmp = n % 10;
    if (tmp == 0) {
      n = n / 10;
      k = k - 1;
    } else {
      k = k - tmp;

      if(k > 0) {      
        n = n - tmp;
      } else {
        n = n - (k + tmp); 
      }

    } 
  }
  printf("%d\n",n);
  return 0; 
}
