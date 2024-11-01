#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string ans(1, s[0]);
        int n = s.length();
        int count = 1;
        for (int i = 1; i < n; i++){
            if (s[i] == ans.back()){
                if (count >= 2) continue;
                else{
                    ans.push_back(s[i]);
                    count++;
                }
            }
            else{
                ans.push_back(s[i]);
                count = 1;
            }
        }
        return ans;
    }
};

int main(){
    string s = "leeetcode";
    // string s = "aaabaaaa";
    // string s = "aab";
    Solution S;
    cout << S.makeFancyString(s) << endl;
    return 0;
}