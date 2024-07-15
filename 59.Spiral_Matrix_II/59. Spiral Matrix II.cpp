#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n, vector<int>(n, 0));
        if (n == 1) {
            matrix[0][0] = 1;
            return matrix;
        };

        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;

        int cnt = 1;
        while ((rowBegin <= rowEnd && colBegin <= colEnd) && (cnt <= n * n)) {
            // Вправо по верхней строке
            for (int j = colBegin; j <= colEnd; ++j) {
                matrix[rowBegin][j] = cnt;
                cnt++;
            }
            ++rowBegin;

            // Вниз по правому столбцу
            for (int i = rowBegin; i <= rowEnd; ++i) {
                matrix[i][colEnd] = cnt;
                cnt++;
            }
            --colEnd;

            if (rowBegin <= rowEnd) {
                // Влево по нижней строке
                for (int j = colEnd; j >= colBegin; --j) {
                    matrix[rowEnd][j] = cnt;
                    cnt++;
                }
            }
            --rowEnd;

            if (colBegin <= colEnd) {
                // Вверх по левому столбцу
                for (int i = rowEnd; i >= rowBegin; --i) {
                    matrix[i][colBegin] = cnt;
                    cnt++;
                }
            }
            ++colBegin;
        }
        return matrix;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res = s.generateMatrix(1);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res.size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}