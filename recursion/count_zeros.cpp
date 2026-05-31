#include <iostream>
using namespace std;

// n >= 0

int zero(int n){
    // base case
    if(n == 0){
        return 1; // If n is 0, return 1 zero
    } else if (n < 10) {
        return 0; // If n is a single digit and not 0, return 0 (no zeros in single digit numbers)
    }

    // recursion and calculation
    int last_digit = n % 10;
    if(last_digit == 0){
        return zero(n / 10) + 1; // If last digit is 0, increment count and continue recursion
    } else {
        return zero(n / 10); // Otherwise, continue recursion without incrementing count
    }
}

int main(){
    cout << zero(200); // Test case: 123450
    return 0;
}
