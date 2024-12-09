#include <iostream>

using namespace std;

int main() {
  //init variables
  int k, n, w, total_cost, borrow_amount;
  cin >> k >> n >> w;
  
  //calculate
  total_cost = ((w * (w+1) ) / 2 )* k;
  borrow_amount = total_cost - n;
  
  //handle no money to borrow
  if (borrow_amount < 0) {
    cout << 0;
    return 0;
  }

  cout << borrow_amount << endl;
  return 0;
}
