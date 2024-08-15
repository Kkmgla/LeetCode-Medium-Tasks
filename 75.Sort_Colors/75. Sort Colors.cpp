#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) r++;
            else if (nums[i] == 1) w++;
            else b++;
        }
        for (int j = 0; j < r; j++) nums[j] = 0;
        for (int j = r; j < w + r; j++) nums[j] = 1;
        for (int j = r + w; j < b + w + r; j++) nums[j] = 2;

        for (int j = 0; j < nums.size(); j++) {
            cout << nums[j] << " ";
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = { 2, 0, 2, 1, 1, 0 };
    s.sortColors(nums);
    return 0;
}
