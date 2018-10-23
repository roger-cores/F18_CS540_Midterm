#include <iostream>
#include <cmath>
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
using namespace std;
class BigInt {
	public:
		BigInt(BigInt &i){
			number = i.number;
			size = i.size;
		}
		BigInt(int array*, int sz){
			number = array;
			size = sz;
		}
		ostream& operator<<(ostream &out, const BigInt &b){
			int i=0;
			for(i=0; i<b.size; i++){
				out << b.number[i];
			}
			return out;
		}
		BigInt BigInt::operator+(BigInt const &b) const {
			
			return b;
		}
		BigInt BigInt::operator+(int const &i) const {
			
			return b;
		}
		BigInt &operator=(const BigInt &s) {
			free(number);
			number = s.number;
			size = s.size;
			
		}
	private:
		int number*;
		int size;
}

BigInt // Return type is wrong.
operator"" _bi(const char * s) {
	int size = 0;
	for (; *s != '\0'; s++) {
		size++; //find the size
	}
	size++; //zero indexed
	number = new int[size];
	int i=0;
	for (; *s != '\0'; s++) {// store the number into an array
		int n = *s - '0';
		number[i] = n;
		i++;
	}
	return new BigInt(number, size);
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



