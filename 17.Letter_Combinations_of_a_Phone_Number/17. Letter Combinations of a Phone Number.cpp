#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;

        map<int, vector<char>> digitToLetters;

        // Заполняем map соответствиями
        digitToLetters[2] = { 'a', 'b', 'c' };
        digitToLetters[3] = { 'd', 'e', 'f' };
        digitToLetters[4] = { 'g', 'h', 'i' };
        digitToLetters[5] = { 'j', 'k', 'l' };
        digitToLetters[6] = { 'm', 'n', 'o' };
        digitToLetters[7] = { 'p', 'q', 'r', 's' };
        digitToLetters[8] = { 't', 'u', 'v' };
        digitToLetters[9] = { 'w', 'x', 'y', 'z' };

        // Начальное значение для комбинаций
        result.push_back("");

        // Обработка нескольких символов
        for (char digitChar : digits) {
            int digit = digitChar - '0'; // Преобразуем символ цифры в целое число
            vector<string> temp;
            for (string s : result) {
                for (char letter : digitToLetters[digit]) {
                    temp.push_back(s + letter); // Добавляем новую комбинацию
                }
            }
            result = temp;
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<string> result = s.letterCombinations("23");
    for (const auto& it : result) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}