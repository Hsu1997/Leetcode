#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        string vowel = "aeiou";
        for (char c : s) if (vowel.find(c) != string::npos) return true;
        return false;
    }
};

int main(){
    string s = "leetcoder";
    // string s = "bbcd";
    Solution S;
    cout << S.doesAliceWin(s) << endl;
    return 0;
}