#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans;
        string::iterator ptr = word.begin();
        for (; ptr != word.end(); ptr++){
            if (*ptr == ch) break;
        }
        if (ptr == word.end()) return word;
        reverse(word.begin(), ptr+1);
        return word;
    }
};

int main(){
    string word = "abcdefd";
    char ch = 'd';
    // string word = "xyxzxe";
    // char ch = 'z';
    // string word = "abcd";
    // char ch = 'z';
    Solution S;
    cout << S.reversePrefix(word, ch) << endl;
    return 0;
}