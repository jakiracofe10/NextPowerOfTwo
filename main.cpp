#include <iostream>

using namespace std;

bool checkIfPowerof2(uint64_t n) {
    if (n<=0) {
        return false;
    }
    //turn off right most bit
    uint64_t x = n & (n-1);
    //if x is 0 then, power of two, because power of two has only one one-bit
    if (!x) {
        return true;
    }
    return false;
}

uint64_t nextPowerOfTwo(uint64_t n) {
    //first check if powerof2 itself
    if (checkIfPowerof2(n)) {
        return n;
    }
    if (n == 0 ) {
        //not possible, return invalid
    }
    //first remove all trailing 1's except msb
    uint64_t x = (((n | (n-1)) + 1) & n);
    //this result will be the closet power of two less than n
    //multiply by two to get next
    x <<= 1;
    return x;

}

//does not work for -1
int main() {
    uint64_t n = 10;
    uint64_t result = nextPowerOfTwo(n);
    cout << result << endl;
    return 0;
}