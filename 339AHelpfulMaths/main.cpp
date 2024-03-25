#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string sum;
    std::cin >> sum;

    // Sort the characters in the string (1s, 2s, and 3s)
    if (sum.size() == 1) {goto done;}
    std::sort(sum.begin(), sum.end());
    // Output the rearranged sum with '+' signs

    for (size_t i = 0; i < sum.size(); ++i) {
        if(sum[i] != '+') {
        std::cout << sum[i];
        if (i != sum.size() - 1) { 
           std::cout << '+';
        }
        }
    }


    std::cout << std::endl;
    return 0;
done:     
    std::cout << sum[0];
    std::cout << std::endl;

    return 0;
}
