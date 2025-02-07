#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<int> queries) {
    for (auto it : queries)
    {
        cout << it << " ";
    }
    cout << endl;
}

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> node, color;
        vector<int> ans;

        for (auto& q : queries) {
            int x = q[0], y = q[1];

            if (node.count(x)) {
                int prevColor = node[x];
                if (prevColor == y) {
                    ans.push_back(color.size());
                    continue;
                }
                if (--color[prevColor] == 0) color.erase(prevColor);
            }

            node[x] = y;
            color[y]++;
            ans.push_back(color.size());
        }

        return ans;
    }
};

int main()
{
    Solution s;
    int limit = 5;
    vector <int> result;
    vector<vector<int>> queries = {
        {1, 4},
        {2, 5},
        {1, 3},
        {3, 4},
    };

    result = s.queryResults(limit, queries);
    printMatrix(result);
}