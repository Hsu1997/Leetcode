#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool b = false;
        for (char c : s){
            if (c == 'a'){
                if (b) return false;
            }
            else b = true;
        }
        return true;
    }
};

int main(){
    string s = "aaabbb";
    // string s = "abab";
    // string s = "bbb";
    Solution S;
    cout << S.checkString(s) << endl;
    return 0;
}