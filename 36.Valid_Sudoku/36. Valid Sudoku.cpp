#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool cellLegitCheck(vector<vector<char>>& board) {
    unordered_set<char> charSet;
    for (int cell = 0; cell < 9; cell++)
    {
        for (int i = 0; i < board.size(); i+=3)
        {
            for (int j = 0; j < board.size(); j+=3)
            {
                int border1 = i + 3;
                int border2 = j + 3;
                for (int x = i; x < border1; x++)
                {
                    for (int y = j; y < border2; y++)
                    {
                        if (charSet.find(board[x][y]) != charSet.end()) {
                            return false;
                        }
                        else
                        {
                            if (!((board[x][y]) == '.'))
                            {
                                charSet.insert((board[x][y]));
                            }
                        }
                    }
                }
                charSet.clear();
            }
        }
    }
    return true;
}

bool legitCheck(vector<vector<char>>& board, int row, int col) {
    unordered_set<char> charSet;
    for (int j = 0; j < board.size(); j++) {
        if (charSet.find(board[row][j]) != charSet.end()) {
            return false;
        }
        else
        {
            if (!((board[row][j]) == '.'))
            {
                charSet.insert((board[row][j]));
            }
        }
    }
    charSet.clear();
    for (int i = 0; i < board.size(); i++) {
        if (charSet.find(board[i][col]) != charSet.end()) {
            return false;
        }
        else
        {
            if (!((board[i][col]) == '.'))
            {
                charSet.insert((board[i][col]));
            }
        }
    }
    return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (!cellLegitCheck(board))
        {
            return false;
        }
        for (int i = 0; i < board.size(); i++) {
            int innerLength = board[i].size();
            for (int j = 0; j < innerLength; j++) {
                if (board[i][j] != '.')
                {
                    if (!legitCheck(board, i, j))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    vector<vector<char>> board1 = {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
    };
    Solution s;
    cout << s.isValidSudoku(board1);
}
/*
1 . 6
5 0 .
. . 7

02
01
00

02
12
22


00 03 06

30 33 36

60 63 66

*/