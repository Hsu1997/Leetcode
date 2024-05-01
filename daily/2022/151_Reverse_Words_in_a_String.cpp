#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int it = 0;
        int len = 0;
        string ans = "";
        while(it < s.length()){
            while(it < s.length() && s[it] == ' ') it++;
            int temp = it;
            len = 0;
            while(temp < s.length() && s[temp] != ' '){
                temp++;
                len++;
            }
            if (len > 0) ans = s.substr(it, len) + " " + ans;
            it = temp + 1;
        }
        ans.pop_back();
        return ans;
    }
};

int main(){
    string s = "the sky is blue";
    // // string s = "  hello world  ";
    // string s = "a good   example";
    Solution S;
    cout << S.reverseWords(s) << "|" << endl;
    return 0;
}