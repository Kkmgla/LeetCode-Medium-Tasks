/* 12. ISeven different symbols represent Roman numerals with the following values :

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Перед V может быть I
Перед L может быть X
Перед D может быть C
Перед X не может быть V
Перед C не может быть L
Перед M не может быть D
*/

class Solution {
public:
    string intToRoman(int num) {
        string ones[] = { "" ,"I" ,"II","III","IV","V","VI","VII","VIII","IX" };
        string tens[] = { "" ,"X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
        string hun[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
        string thn[] = { "","M","MM","MMM" };

        return thn[num / 1000] + hun[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(1511);
}