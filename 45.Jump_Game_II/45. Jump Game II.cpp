/*Первый вариант(мой) - выдает ошибку time limit exceeded
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;

public:
    void recur(vector<int>& tmpRes, vector<int>& nums, int start) {
        if (start >= nums.size() - 1)
        {
            result.push_back(tmpRes); 
            return;
        }
        int tmp = nums[start] + start;
        for (int j = start; (j < tmp) && (j < nums.size() - 1); j++)
        {
            if ((nums[j + 1] != 0) || (j != nums.size() - 1)) {
                tmpRes.push_back(nums[j + 1]);
                recur(tmpRes, nums, j + 1);
                tmpRes.pop_back();
            }
        }
    }

    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        vector<int> tmpRes = { nums[0] };

        recur(tmpRes, nums, 0);
        int minSize = INT_MAX;
        for (auto it: result)
        {
            if (it.size() < minSize) minSize = it.size();
        }
        return minSize - 1;
    }
};

int main()
{
    Solution s;
    vector<int>nums = { 5,9,3,2,1,0,2,3,3,1,0,0 };
    cout << s.jump(nums);
}
*/

//второй вариант (gpt) жадный алгоритм :(
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int jumps = 0, current_end = 0, farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                if (current_end >= n - 1) break;
            }
        }

        return jumps;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 2, 3, 1, 1, 4 };
    cout << s.jump(nums) << endl;
    return 0;
}