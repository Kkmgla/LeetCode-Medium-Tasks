#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> zeroRows(rows, false);
        vector<bool> zeroCols(cols, false);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            if (zeroRows[i]) {
                for (int j = 0; j < cols; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < cols; ++j) {
            if (zeroCols[j]) {
                for (int i = 0; i < rows; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (const auto& row : matrix) {
            for (int elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = { {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5} };
    s.setZeroes(matrix);
    return 0;
}
