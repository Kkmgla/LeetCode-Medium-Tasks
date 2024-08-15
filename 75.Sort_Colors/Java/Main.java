public class Main {
    public static void main(String[] args) {
        class Solution {
            public void sortColors(int[] nums) {
                int r = 0, w = 0, b = 0;
                for (int i = 0; i < nums.length; i++) {
                    if (nums[i] == 0) r++;
                    else if (nums[i] == 1) w++;
                    else b++;
                }

                for (int j = 0; j < r; j++) nums[j] = 0;
                for (int j = r; j < w + r; j++) nums[j] = 1;
                for (int j = r + w; j < b + w + r; j++) nums[j] = 2;

                for (int j = 0; j < nums.length; j++) {
                    System.out.print(nums[j] + " ");
                }
            }
        }

        Solution s = new Solution();
        int[] nums = {2,0,2,1,1,0};
        s.sortColors(nums);
    }
}