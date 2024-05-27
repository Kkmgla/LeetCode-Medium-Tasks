/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> sortThreeNumbers(int a, int b, int c) {
    std::vector<int> sortedVec = { a, b, c };
    std::sort(sortedVec.begin(), sortedVec.end());
    return sortedVec;
}


vector<vector<int>> killAllDuplicates(vector<vector<int>>& result) {
    // Сортируем вектор векторов, чтобы одинаковые векторы были рядом
    sort(result.begin(), result.end());

    // Используем уникальный указатель на конец вектора после удаления дубликатов
    auto last = unique(result.begin(), result.end());

    // Удаляем дубликаты
    result.erase(last, result.end());
    return result;
}

void printVector(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                for (int k = 0; k < nums.size(); k++)
                {
                    if ((i != j && i != k && j != k) && (nums[i] + nums[j] + nums[k] == 0))
                    {
                        sortThreeNumbers(nums[i], nums[j], nums[k]);
                        vector<int>tmp(sortThreeNumbers(nums[i], nums[j], nums[k]));
                        result.push_back(tmp);
                    }
                }
            }
        }
        result = killAllDuplicates(result);
        return result;
    }
};
/*
-1  0   1   2   -1  -4







*/
int main()
{
    Solution s;
    vector<int> nums{ -1,0,1,2,-1,-4 };
    printVector(s.threeSum(nums));
}