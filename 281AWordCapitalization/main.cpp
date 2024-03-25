#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string word;
    std::cin >> word;

    // Capitalize the first letter if it's lowercase
    if (word[0] >= 'a' && word[0] <= 'z') {
        word[0] -= 32;  // Convert lowercase to uppercase
    }

    std::cout << word << std::endl;
    return 0;
} 
