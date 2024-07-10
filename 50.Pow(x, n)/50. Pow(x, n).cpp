#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double result = x;
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (abs(x) == 1) {
            if (n % 2 != 0)
            {
                return x;
            }
            return abs(x);
        }
        if (n == 1) return x;
        for (int i = 0; i < abs(n) - 1; i++)
        {
            result = result * x;
        }
        if (n < 0) result = 1 / result;
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2, 2147483648);
}