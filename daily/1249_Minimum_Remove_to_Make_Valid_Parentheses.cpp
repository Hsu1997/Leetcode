#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int parentheses = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '(') parentheses++;
            if (s[i] == ')'){
                if (parentheses > 0) parentheses--;
                else{
                    // s.erase(i,1);
                    s[i] = '\0';
                }
            }
        }
        int n = s.length() - 1;
        while(parentheses > 0){
            if (s[n] == '('){
                // s.erase(n,1);
                s[n] = '\0';
                parentheses--;
            }
            n--;
        }
        string ans;
        for (int i = 0; i < s.length(); i++){
            if (s[i]) ans += s[i];
        }
        return ans;
    }
};

int main(){
    string s = "lee(t(c)o)de)";
    Solution S;
    cout << S.minRemoveToMakeValid(s) << endl;
    return 0;
}