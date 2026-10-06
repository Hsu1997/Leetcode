#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int p = 0;
        int open = 0;
        for (char c : s){
            if (c == '*') p++;
            else if (c == '(') open++;
            else{
                if (open) open--;
                else if (p) p--;
                else return false;
            }
        }
        p = 0;
        int close = 0;
        for (int i = s.length() - 1; i >= 0; i--){
            char c = s[i];
            if (c == '*') p++;
            else if (c == ')') close++;
            else{
                if (close) close--;
                else if (p) p--;
                else return false;
            }
        }
        return true;
    }
};

int main(){
    string s = "()";
    // string s = "(*)";
    // string s = "(*))";
    // string s = "(";
    Solution S;
    cout << S.checkValidString(s) << endl;
    return 0;
}