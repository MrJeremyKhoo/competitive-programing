#include <iostream>
#include <cmath> // Include cmath for logarithm function

int main() {
  int a, b;
  //Solve by mathematical model
  std::cin >> a >> b;
  double x = std::log(static_cast<double>(b) / a) / std::log(1.5);

  //More than equals check; must check that x is not a whole number
  int years;
  if(std::floor(x) == x) { //then x was whole numebr
  years = static_cast<int>(std::ceil(x)) + 1;

  } else {
    years = static_cast<int>(std::ceil(x));
  }
  std::cout << years << std::endl;
  return 0;
}
