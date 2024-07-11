#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0) sum = 0;
        }
        return maxi;
    }
};

int main()
{
    Solution s;
    vector<int>nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    cout << s.maxSubArray(nums);
}
// -2, 1, -3, 4, -5, 2, 1, -5, 3