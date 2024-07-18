#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long uniquePaths(int m, int n) {
        long long ans = 1;
        int totalSteps = m + n - 2;
        int stepsToChoose = min(m - 1, n - 1);

        // Calculate C(totalSteps, stepsToChoose) directly
        for (int i = 1; i <= stepsToChoose; ++i) {
            ans = ans * (totalSteps - i + 1) / i;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int rows = 3, cols = 7;
    cout << s.uniquePaths(rows, cols);
}