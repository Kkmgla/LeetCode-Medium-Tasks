#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
class Solution {
public:
     time limit exceeded
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>groupedStrs;
        for (int i = 0; i < strs.size(); i++)
        {
            if (groupedStrs.empty())
            {
                vector<string>tmpVec = { strs[i] };
                groupedStrs.push_back(tmpVec);
            }
            else
            {
                bool add = 0;
                string tmpStr1 = strs[i];
                sort(tmpStr1.begin(), tmpStr1.end());

                for (auto &it : groupedStrs)
                {
                    string tmpStr2 = it[0];
                    sort(tmpStr2.begin(), tmpStr2.end());

                    if (tmpStr1 == tmpStr2)
                    {
                        it.push_back(strs[i]);
                        add = 1;
                    }
                }
                if (!add)
                {
                    vector<string>tmpVec = { strs[i] };
                    groupedStrs.push_back(tmpVec);
                }
            }
        }
        return groupedStrs;
    }
};
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myMap;
        for (auto& ele : strs) {
            string eleSorted = ele;
            sort(eleSorted.begin(), eleSorted.end());
            myMap[eleSorted].push_back(ele);
        }
        vector<vector<string>> result;
        for (auto& pair : myMap) {
            result.push_back(pair.second);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
    vector<vector<string>>groupedStrs = s.groupAnagrams(strs);
    for (auto it : groupedStrs) {
        for (auto nr : it) {
            cout << nr << " ";
        }
        cout << endl;
    }
}