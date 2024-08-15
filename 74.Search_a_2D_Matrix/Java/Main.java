public class Main {
    public static void main(String[] args) {

    }
     class Solution {
        public boolean searchMatrix(int[][] matrix, int target) {
            int i = 0;
            for (i = 0; i < matrix.length - 1; i++){
                if(target < matrix[i + 1][0]) break;
            }
            for (int j = 0; j < matrix[0].length; j++){
                if (matrix[i][j] == target) return true;
                else if(matrix[i][j] > target) return false;
            }
            return false;
        }
    }
}