#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string ans;
        for (char c : s){
            if (c == '*'){
                if (!ans.empty()) ans.pop_back();
            }
            else if (c == '#') ans += ans;
            else if (c == '%') reverse(ans.begin(), ans.end());
            else ans += c;
        }
        return ans;
    }
};

int main(){
    string s = "a#b%*";
    // string s = "z*#";
    Solution S;
    cout << S.processStr(s) << endl;
    return 0;
}