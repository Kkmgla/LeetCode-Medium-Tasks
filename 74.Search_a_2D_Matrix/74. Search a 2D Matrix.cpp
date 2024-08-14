#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        for (i; i < matrix.size() - 1; i++)
        {
            if (target < matrix[i + 1][0]) break;
        }
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == target) return 1;
            else if (matrix[i][j] > target) return 0;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = { {1, 3, 5, 7},{10, 11, 16, 20}, {23, 30, 34, 60} };
    int target = 12;
    cout << s.searchMatrix(matrix, target);
}