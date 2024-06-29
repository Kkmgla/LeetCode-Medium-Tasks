#include <iostream>
#include <string>

using namespace std;

string compressRLE(const string& input) {
    string compressed;
    int count = 1;
    int i = 1;

    while (i <= input.size()) {
        if (i == input.size() || input[i - 1] != input[i]) {
            compressed.append(to_string(count));
            compressed.append(1, input[i - 1]);
            count = 1;
        }
        else {
            count++;
        }
        i++;
    }

    return compressed;
}

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        if (n == 1) return result;

        for (int i = 2; i <= n; i++) {
            cout << "Step " << i << ": " << result << endl; // Debug message
            result = compressRLE(result);
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(7) << endl;
    return 0;
}

//1
//11
//21
//1211
//111221
//312211
//13112221
//1113213211