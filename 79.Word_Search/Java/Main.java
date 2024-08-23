import java.util.List;

public class Main {
    public static void main(String[] args) {
        class Solution {
            public boolean exist(char[][] board, String word) {
                boolean[][] visited = new boolean[board.length][board[0].length];

                for (int i = 0; i < board.length; i++) {
                    for (int j = 0; j < board[0].length; j++) {
                        // Начинаем поиск только если первая буква совпадает
                        if (board[i][j] == word.charAt(0)) {
                            if (bt(board, word, i, j, 0, visited)) {
                                return true;
                            }
                        }
                    }
                }
                return false;
            }
            private boolean bt(char[][] board, String word, int x, int y, int index, boolean[][] visited) {
                if (index == word.length()) return true;
                // Проверка границ и состояния посещения ячейки
                if (x < 0 || x >= board.length || y < 0 || y >= board[0].length || visited[x][y] || board[x][y] != word.charAt(index)) {
                    return false;
                }
                // Отмечаем текущую ячейку как посещённую
                visited[x][y] = true;

                // Рекурсивный вызов для всех соседей (вверх, вниз, влево, вправо)
                boolean found = bt(board, word, x - 1, y, index + 1, visited) ||
                        bt(board, word, x + 1, y, index + 1, visited) ||
                        bt(board, word, x, y - 1, index + 1, visited) ||
                        bt(board, word, x, y + 1, index + 1, visited);

                // Снимаем отметку посещения (backtrack)
                visited[x][y] = false;

                return found;
            }
        }
    }
}