/*
Given a string s, find the length of the longest
substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;   //���� �������� ������ ������� �����, ���������� 0

        unordered_map<char, int> m;   ///������� ����� ��� �������� ������� (��� ��������� ���������� ����)
        int i = 0;
        int j = 0;
        int ans = INT_MIN;

        while (j < s.length())
        {
            m[s[j]]++;  //������������ ������� �������� ��� ����������� �� ������
            if (m.size() == j - i + 1)  //���� ������ ����� ����� ������� ����, ��� ������������, ��� ������ ���� ����� 3, � ������ ����� ����� ����� ����, ��� ��������, ��� ����� ������� ������ �� ���������� �����
            {
                ans = max(ans, j - i + 1);  //���������� ����� ������������� ������� ����
            }
            else if (m.size() < j - i + 1)   //���� ������ ����� ������ ������� ����, ��� ��������, ��� ������������ �����-�� ��������, �������� ������ ���� = 3, � ������ ����� = 2 ��������, ��� ���� ���������
            {
                while (m.size() < j - i + 1)  //so till the duplicates are removed completely
                {
                    m[s[i]]--;   //������� �����
                    if (m[s[i]] == 0)  //���� ������� ����� 0
                    {
                        m.erase(s[i]);//������� ���������
                    }
                    i++;  //��������� � ���������� ��������
                }
            }
            j++;  //��������� � ���������� ��������
        }
        return ans;
    }
};


// ���� ������� �������, ����� ������� � ����������, �� ������� ������ �� ������� ������� ������ (31000char)
/*
class Solution {

    string repStr = "";
    bool rep = 0;
    int cnt = 0;
    int tmpCnt = 0;
    int pp = 0;

public:
    
int lengthOfLongestSubstring(string s) {
        int i = 0;
        if (s.size() == 0) return 0;
        else if (s.size() == 1) return 1;
        for (int l = 0; l < s.size(); l++)
        {
            for (i = pp; i < s.size(); i++)
            {
                for (int j = 0; j < repStr.size(); j++)
                {
                    if (repStr[j] == s[i])
                    {
                        rep = 1;
                        break;
                    }
                }
                if (rep)
                {
                    if (tmpCnt > cnt)
                    {
                        cnt = tmpCnt;
                    }
                    tmpCnt = 0;
                    repStr = "";
                }
                else
                {
                    tmpCnt++;
                    repStr += s[i];
                }
            }

            pp++;
            rep = 0;
        }
        return cnt;
    }
};
*/

int main()
{
    string str = "asassFVDFD";
    Solution s;
    int n = s.lengthOfLongestSubstring(str);
    cout << n;
}