#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if (matrix.empty()) return result;

        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // Вправо по верхней строке
            for (int j = colBegin; j <= colEnd; ++j) {
                result.push_back(matrix[rowBegin][j]);
            }
            ++rowBegin;

            // Вниз по правому столбцу
            for (int i = rowBegin; i <= rowEnd; ++i) {
                result.push_back(matrix[i][colEnd]);
            }
            --colEnd;

            if (rowBegin <= rowEnd) {
                // Влево по нижней строке
                for (int j = colEnd; j >= colBegin; --j) {
                    result.push_back(matrix[rowEnd][j]);
                }
            }
            --rowEnd;

            if (colBegin <= colEnd) {
                // Вверх по левому столбцу
                for (int i = rowEnd; i >= rowBegin; --i) {
                    result.push_back(matrix[i][colBegin]);
                }
            }
            ++colBegin;
        }

        return result;
    }
};

int main() {
    Solution s;

    const int rows = 6;
    const int cols = 8;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    // Заполнение матрицы числами от 1 до 48
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = value++;
        }
    }

    vector<int> res = s.spiralOrder(matrix);

    // Вывод результата
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

/*
00 01 02 03 04 05 06 07
10 11 12 13 14 15 16 17
20 21 22 23 24 25 26 27
30 31 32 33 34 35 36 37
40 41 42 43 44 45 46 47
50 51 52 53 54 55 56 57

0 8
1 6
2 4


1 4
2 2




1  2  3  4  5  6  7  8
9  10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
*/