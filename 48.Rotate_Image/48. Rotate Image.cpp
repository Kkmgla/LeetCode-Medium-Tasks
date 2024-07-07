// 48. Rotate Image.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int>tmp;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = matrix.size() - 1; j >= 0; j--)
            {
                tmp.push_back(matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                matrix[i][j] = tmp[j + (i * matrix.size())];
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>>matrix = {{ 1,2,3 }, { 4, 5, 6 }, { 7, 8, 9 }};
    s.rotate(matrix);
}
/*
1 2 3
4 5 6
7 8 9
*/