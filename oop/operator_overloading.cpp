#include <iostream>
using namespace std;

class Fraction {
private:
    int num;
    int den;

public:
    Fraction(int num, int den) {
        this->num = num;
        this->den = den;
    }

    void print() const {
        cout << num << "/" << den << endl;
    }

    void simplify() {
        int gcd = 1;
        int limit = min(num, den);
        for (int i = 1; i <= limit; i++) {
            if (num % i == 0 && den % i == 0) {
                gcd = i;
            }
        }
        num = num / gcd;
        den = den / gcd;
    }

    // Overloading '+' operator (Binary Operator)
    Fraction operator+(Fraction const &f2) const {
        int lcm = den * f2.den;
        int x = lcm / den;
        int y = lcm / f2.den;
        int newNum = x * num + y * f2.num;
        Fraction fNew(newNum, lcm);
        fNew.simplify();
        return fNew;
    }

    // Overloading '*' operator (Binary Operator)
    Fraction operator*(Fraction const &f2) const {
        int newNum = num * f2.num;
        int newDen = den * f2.den;
        Fraction fNew(newNum, newDen);
        fNew.simplify();
        return fNew;
    }

    // Overloading '==' operator (Comparison Operator)
    bool operator==(Fraction const &f2) const {
        // Create temporary copies and simplify them to compare
        Fraction f1Copy(num, den);
        Fraction f2Copy(f2.num, f2.den);
        f1Copy.simplify();
        f2Copy.simplify();
        return (f1Copy.num == f2Copy.num && f1Copy.den == f2Copy.den);
    }

    // Overloading '++' pre-increment operator (Unary Operator)
    Fraction& operator++() {
        num = num + den;
        simplify();
        return *this;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(2, 3);

    cout << "Fraction 1: ";
    f1.print();
    cout << "Fraction 2: ";
    f2.print();

    // Test '+' operator overloading
    Fraction f3 = f1 + f2;
    cout << "f1 + f2 = ";
    f3.print();

    // Test '*' operator overloading
    Fraction f4 = f1 * f2;
    cout << "f1 * f2 = ";
    f4.print();

    // Test '==' operator overloading
    Fraction f5(2, 4);
    if (f1 == f5) {
        cout << "f1 (1/2) is equal to f5 (2/4)" << endl;
    } else {
        cout << "f1 and f5 are not equal" << endl;
    }

    // Test pre-increment '++' operator overloading
    cout << "Before pre-increment, f1: ";
    f1.print();
    Fraction f6 = ++f1;
    cout << "After pre-increment, f1: ";
    f1.print();
    cout << "Returned Fraction f6: ";
    f6.print();

    return 0;
}
