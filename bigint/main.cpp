#include <iostream>

/*
 * -------------------------------------------------------------------------------------------------
 * The BigInt class represents an arbitrary precision integer.
 *
 * Addition should be O(D), where D is the number of digits.
 * In other words, you need to use an efficient algorithm for addition.
 *
 * NOTE:
 * 1. You are not supposed to use c++ standard containers like std::vector etc...
 * 2. Digits can vary to any number so don't hardcode the size to 30 digits for below example.
 * 3. No need to handle negative numbers.
 * 4. You do not need to support subtraction, multiplication.
 * 5. Make sure your code should not have Memory errors and leaks.
 * -------------------------------------------------------------------------------------------------
 */


// Your implementation here ...


void // Return type is wrong.
operator"" _bi(const char *) {
}

int
main() {

    // 30 digits.
    BigInt i{123456789012345678901234567890_bi};
    std::cout << i << std::endl;

    // Use implicit conversion.
    auto j = i + 2;
    std::cout << j << std::endl;

    // Use implicit conversion.
    j = 3 + j;
    std::cout << j << std::endl;

    j = i + j;
    std::cout << j << std::endl;

    j = j;
    std::cout << j << std::endl;

    // 20 digits.
    BigInt k{12345678901234567890_bi};
    auto l = i + j + k;
    std::cout << l << std::endl;
}



