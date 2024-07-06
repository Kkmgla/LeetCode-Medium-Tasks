#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result = { nums };
        vector<int>primaryNums = nums;
        do {
            next_permutation(nums.begin(), nums.end());
            result.push_back(nums);

        } while (nums != primaryNums);

        result.pop_back();
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1, 3, 3 };
    vector<vector<int>>result = s.permuteUnique(nums);
    for (auto it : result) {
        for (auto en : it) {
            cout << en << " ";
        }
        cout << endl;
    }
}