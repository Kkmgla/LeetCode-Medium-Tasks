/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows: string convert(string s, int numRows);
*/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string matrixToString(const vector<vector<char>>& matrix) {
    ostringstream oss;
    for (const auto& row : matrix) {
        for (char element : row) {
            if (element != '\0') // Пропускаем пустые ячейки
                oss << element;
        }
    }
    return oss.str();
}

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; // Особый случай, если numRows равно 1

        vector<vector<char>> matrix(numRows, vector<char>(s.length(), '\0')); // Инициализация матрицы
        int i = 0, j = 0;
        bool down = true; // Флаг для определения направления

        for (char c : s) {
            matrix[i][j] = c;
            if (down) {
                if (i == numRows - 1) {
                    down = false;
                    i--;
                    j++;
                }
                else {
                    i++;
                }
            }
            else {
                if (i == 0) {
                    down = true;
                    i++;
                }
                else {
                    i--;
                    j++;
                }
            }
        }

        return matrixToString(matrix);
    }
};

int main() {
    Solution s;
    string str = "PAYPALISHIRING";
    int numRows = 4;
    cout << s.convert(str, numRows) << endl;
    return 0;
}