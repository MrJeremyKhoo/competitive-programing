#include <iostream>
#include <string>
#include <bitset>

int main() {
    std::string username;
    std::cin >> username;

    std::bitset<26> seenCharacters; 
    int distinctCount = 0; // Keep track of the count of distinct characters

    for (char c : username) {
        if (!seenCharacters.test(c - 'a')) { // Check if the character is seen before
            seenCharacters.set(c - 'a');
            distinctCount++; 
        }
    }

    if (distinctCount % 2 == 0) {
        std::cout << "CHAT WITH HER!" << std::endl;
    } else {
        std::cout << "IGNORE HIM!" << std::endl;
    }

    return 0;
}
