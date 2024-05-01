#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '#'){
                if (!s1.empty()) s1.pop();
            }
            else s1.push(s[i]);
        }
        for (int i = 0; i < t.size(); i++){
            if (t[i] == '#'){
                if (!s2.empty()) s2.pop();
            }
            else s2.push(t[i]);
        }
        // cout << s1.size() << " " <<  s2.size() << endl;
        if (s1.size() != s2.size()) return false;
        int count = s1.size();
        for (int i = 0; i < count; i++){
            // cout << i << " " << s1.top() << " " << s2.top() << endl;
            if (s1.top() == s2.top()){
                s1.pop();
                s2.pop();
            }
            else return false;
        }
        return true;
    }
};

int main(){
    // string s = "ab#c";
    // string t = "ad#c";
    // string s = "a##c";
    // string t = "#a#c";
    string s = "abcd";  
    string t = "bbcd";  

    Solution S;
    cout << S.backspaceCompare(s, t) << endl;
    return 0;
}