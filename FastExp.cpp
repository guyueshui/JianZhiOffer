// Problem:
// 给定一个double类型的浮点数base
// 和int类型的整数exponent。
// 求base的exponent次方。

/*
 * Apply the fast-exp method. DO NOT forget that
 * `int` can be negative.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    // recursive O(log(power))
    double exp(double base, int power) {
        if (power == 0) return 1;
        else if (power & 1) // power is odd
            return base * exp(base, power - 1);
        else // power is even
            return [](double x) -> double {
                return x * x;
            }(exp(base, power >> 1));
    }

    // iterative O(log(power))
    double fastexp(double base, int p) {
        double ret = 1;
        int power = p;

        // what if p<0?
        if (power < 0) {
            if (base == 0)
                throw "divde by zero!";
            power = -power;
        }

        while (power) {
            if (power & 1)
                ret *= base;
            base *= base;
            power >>= 1;
        }
        return (p < 0)? (1/ret) : ret;
    }
};

int main(int argc, const char* argv[]) {
    double base = std::stod(argv[1]),
           power = std::stoi(argv[2]);
    try {
        cout << Solution().fastexp(base, power);
    } catch(const char* errmsg) {
        cerr << errmsg;
    }
    return 0;
}
