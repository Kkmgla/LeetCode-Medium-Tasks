#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*TIME LIMIT EXCEEDED
class Solution {
    long long minSum = LLONG_MIN;
public:
    void recFun(vector<vector<int>>& grid, int x, int y, long long currentSum) {
        if (currentSum > minSum) return;
        if ((x == grid.size() - 1) && (y == grid[0].size() - 1) && (currentSum <= minSum))
        {
            minSum = currentSum;
        }
        if (x + 1 < grid.size())
        {
            recFun(grid, x + 1, y, currentSum + grid[x + 1][y]);
        }
        if (y + 1 < grid[0].size())
        {
            recFun(grid, x, y + 1, currentSum + grid[x][y + 1]);
        }
        return;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int coordX = 0, coordY = 0;
        long long currentSum = grid[0][0];
        recFun(grid, coordX, coordY, currentSum);
        return minSum;
    }
};
*/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Создаем DP массив для хранения минимальных сумм путей
        vector<vector<long long>> dp(m, vector<long long>(n, INT_MAX));

        // Начальная точка
        dp[0][0] = grid[0][0];

        // Заполняем DP массив
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                long long left = (j > 0) ? dp[i][j - 1] : INT_MAX;
                long long top = (i > 0) ? dp[i - 1][j] : INT_MAX;

                dp[i][j] = min(left, top) + grid[i][j];
            }
        }
        
        for (auto it : dp) {
            for (auto ti : it) {
                cout << ti << " ";
            }
            cout << endl;
        }

        return dp[m - 1][n - 1];
    }
};


int main()
{
    Solution s;
    /*
    1 3 5
    4 6 8
    7 1 5
    */
    vector<vector<int>>mat = { {1,3,1},{1,5,1},{4,2,1} };
    cout << s.minPathSum(mat);
}

// x y
// 00 01 02 03
// 10 11 12 13
// 20 21 22 23