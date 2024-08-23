import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        class Solution {
            public List<List<Integer>> combine(int n, int k) {
                List<List<Integer>> result = new ArrayList<>();
                List<Integer> comb = new ArrayList<>();
                backtrack(1, comb, result, n, k);
                return result;
            }
            private void backtrack(int start, List<Integer> comb, List<List<Integer>> result, int n, int k) {
                if(comb.size() == k){
                    result.add(new ArrayList<>(comb));
                    return;
                }

                for (int i = start; i <= n; i++){
                    comb.add(i);
                    backtrack(i + 1, comb, result, n, k);
                    comb.remove(comb.size() - 1);
                };
            }
        };

        Solution s = new Solution();
        List<List<Integer>> tmp = s.combine(4, 2);
        for (List<Integer> i : tmp){
            for (Integer j : i){
                System.out.println(j);
            }
            System.out.println("\n");
        }
    }
}
/*
n = 4
k = 2



*/