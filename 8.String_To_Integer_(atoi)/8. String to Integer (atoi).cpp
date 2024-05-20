/* 
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:
Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. 
If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. 
Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <climits> // Äëÿ INT_MIN è INT_MAX
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int sign = 1;
        int i = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        for (i; i <= s.length() - 1; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int digit = s[i] - '0';
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                    return (sign == 1) ? INT_MAX : INT_MIN;
                }
                result = result * 10;
                result = result + digit;
            }
            else if (((s[i] == '-') || (s[i] == '+')) && i < s.length() - 1 && s[i + 1] >= '0' && s[i + 1] <= '9' && (i == 0 || !isdigit(s[i - 1]))) {
                if (s[i] == '-') sign = -1;
            }
            else break;
        }
        return result * sign;
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi("+1");
}