#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;

        backtrack(1, comb, res, n, k);
        return res;
    }

private:
    void backtrack(int start, vector<int>& comb, vector<vector<int>>& res, int n, int k) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int num = start; num <= n; num++) {
            comb.push_back(num);
            backtrack(num + 1, comb, res, n, k);
            comb.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);
}

/*
n = 4,
k = 2

12 13 14
23 24
34

n = 4
k = 3

123 124
234

n = 4
k = 4





*/