#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // ������ ��� ������������ ���������� �����
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // �������� ����� ������ ���� ������ ����� ���������
                if (board[i][j] == word[0]) {
                    if (bt(board, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool bt(vector<vector<char>>& board, string word, int x, int y, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) {
            return true;
        }

        // �������� ������ � ��������� ��������� ������
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y] || board[x][y] != word[index]) {
            return false;
        }

        // �������� ������� ������ ��� ����������
        visited[x][y] = true;

        // ����������� ����� ��� ���� ������� (�����, ����, �����, ������)
        bool found = bt(board, word, x - 1, y, index + 1, visited) ||
            bt(board, word, x + 1, y, index + 1, visited) ||
            bt(board, word, x, y - 1, index + 1, visited) ||
            bt(board, word, x, y + 1, index + 1, visited);

        // ������� ������� ��������� (backtrack)
        visited[x][y] = false;

        return found;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    string word = "SEE";
    cout << (s.exist(board, word) ? "true" : "false") << endl; // ��������� ���������: true
}
