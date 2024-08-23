#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Массив для отслеживания посещённых ячеек
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Начинаем поиск только если первая буква совпадает
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

        // Проверка границ и состояния посещения ячейки
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y] || board[x][y] != word[index]) {
            return false;
        }

        // Отмечаем текущую ячейку как посещённую
        visited[x][y] = true;

        // Рекурсивный вызов для всех соседей (вверх, вниз, влево, вправо)
        bool found = bt(board, word, x - 1, y, index + 1, visited) ||
            bt(board, word, x + 1, y, index + 1, visited) ||
            bt(board, word, x, y - 1, index + 1, visited) ||
            bt(board, word, x, y + 1, index + 1, visited);

        // Снимаем отметку посещения (backtrack)
        visited[x][y] = false;

        return found;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    string word = "SEE";
    cout << (s.exist(board, word) ? "true" : "false") << endl; // Ожидаемый результат: true
}
