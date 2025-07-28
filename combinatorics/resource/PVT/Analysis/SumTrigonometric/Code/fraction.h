#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction {
    private:
        // Calculates the greates common divisor with
        // Euclid's algorithm
        // both arguments have to be positive
        long long gcd(long long a, long long b) {
            a = std::abs(a); // Ensure positive inputs
            b = std::abs(b);
            while (b) {
                a %= b;
                std::swap(a, b);
            }
            return a;
        }

        void check_overflow(long long a, long long b) {
            if (a > LLONG_MAX / 2 || b > LLONG_MAX / 2) {
                std::cerr << "Warning: Potential overflow in Fraction arithmetic." << std::endl;
            }
        }

    public:
        long long numerator, denominator;

        Fraction() {
            numerator = 0;
            denominator = 1;
        }

        Fraction(long long n, long long d) {
            if (d == 0) {
                cerr << "Denominator may not be 0." << endl;
                exit(0);
            } else if (n == 0) {
                numerator = 0;
                denominator = 1;
            } else {
                int sign = 1;
                if (n < 0) {
                    sign *= -1;
                    n *= -1;
                }
                if (d < 0) {
                    sign *= -1;
                    d *= -1;
                }
                check_overflow(n, d);
                long long tmp = gcd(n, d);
                numerator = n/tmp*sign;
                denominator = d/tmp;
            }
        }

        operator int() {return (numerator)/denominator;}
        operator float() {return ((float)numerator)/denominator;}
        operator double() {return ((double)numerator)/denominator;}
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator+=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator-=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.numerator,
               lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator*=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.numerator,
               lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(int lhs, const Fraction& rhs) {
    Fraction tmp(lhs*rhs.numerator,rhs.denominator);
    return tmp;
}

Fraction operator*(const Fraction& rhs, int lhs) {
    Fraction tmp(lhs*rhs.numerator,rhs.denominator);
    return tmp;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator,
                 lhs.denominator*rhs.numerator);
    return tmp;
}

std::ostream& operator<<(std::ostream &strm, const Fraction &a) {
    if (a.denominator == 1) {
        strm << a.numerator;
    } else {
        strm << a.numerator << "/" << a.denominator;
    }
    return strm;
}

bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.numerator*rhs.denominator == lhs.denominator*rhs.numerator);
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return (((lhs.numerator*rhs.denominator-lhs.denominator*rhs.numerator) * lhs.denominator * rhs.denominator) < 0);
}

bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return (((lhs.numerator*rhs.denominator-lhs.denominator*rhs.numerator) * lhs.denominator * rhs.denominator) > 0);
}

bool operator<=(const Fraction& lhs, const Fraction& rhs) {
    return ((lhs < rhs) || (lhs == rhs));
}

bool operator>=(const Fraction& lhs, const Fraction& rhs) {
    return ((lhs > rhs) || (lhs == rhs));
}

#endif // FRACTION_H