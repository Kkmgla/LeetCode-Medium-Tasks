/*
You are given an integer array height of length n.
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            int width = right - left;
            int current_height = min(height[left], height[right]);
            int tmp_area = width * current_height;

            max_area = max(max_area, tmp_area);

            // Двигаем указатель меньшей линии внутрь
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return max_area;
    }
};

int main() {
    Solution s;
    vector<int> height{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << s.maxArea(height) << endl;
}
