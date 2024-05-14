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
        if (s.length() == 0) return 0;   //если приходит строка нулевой длины, возвращаем 0

        unordered_map<char, int> m;   ///создаем карту для хранения частоты (все извеснтые уникальные чары)
        int i = 0;
        int j = 0;
        int ans = INT_MIN;

        while (j < s.length())
        {
            m[s[j]]++;  //увеличивайте частоту элемента при перемещении по строке
            if (m.size() == j - i + 1)  //если размер карты равен размеру окна, это предполагает, что размер окна равен 3, а размер карты также равен трем, что означает, что карта состоит только из уникальных чаров
            {
                ans = max(ans, j - i + 1);  //сравниваем длину максимального размера окна
            }
            else if (m.size() < j - i + 1)   //если размер карты меньше размера окна, это означает, что присутствует какой-то дубликат, например размер окна = 3, а размер карты = 2 означает, что есть дубликаты
            {
                while (m.size() < j - i + 1)  //so till the duplicates are removed completely
                {
                    m[s[i]]--;   //удаляем дубли
                    if (m[s[i]] == 0)  //если частота равна 0
                    {
                        m.erase(s[i]);//удаляем полностью
                    }
                    i++;  //переходим к следующему элементу
                }
            }
            j++;  //переходим к следующему элементу
        }
        return ans;
    }
};


// Тоже рабочий вариант, более простой в реализации, но слишком долгий на больших объемах данных (31000char)
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