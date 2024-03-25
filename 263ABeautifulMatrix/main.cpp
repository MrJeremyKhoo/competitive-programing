#include <iostream>
#include <cstdlib>  // For abs()
 
int main() {
    int num;
    int rowOne, colOne; // Store the coordinates where '1' is found
    // Read the input matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> num;
            if (num == 1) {
                rowOne = i;
                colOne = j;
                goto done;
            }
        }
    }
    done:
    // Calculate the moves needed
    int rowMoves = std::abs(rowOne - 2);  // Moves to bring '1' to row 3
    int colMoves = std::abs(colOne - 2);  // Moves to bring '1' to column 3
 
    // Output the result
    std::cout << rowMoves + colMoves << std::endl;
 
    return 0;
}
