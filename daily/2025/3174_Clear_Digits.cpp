#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        int del = 0;
        int n = s.length();
        string ans;
        for (int i = n-1; i >= 0; i--){
            if (isdigit(s[i])){
                del++;
            }
            else{
                if (del > 0) del--;
                else{
                    ans += s[i];
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    string s = "abc";
    // string s = "cb34";
    Solution S;
    cout << S.clearDigits(s) << endl;
    return 0;
}