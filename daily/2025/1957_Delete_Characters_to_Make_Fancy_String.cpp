#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char prev = '.';
        int cnt = 0;
        for (char c : s){
            if (c == prev){
                if (cnt >= 2) continue;
                else{
                    cnt++;
                    ans.push_back(c);
                }
            }
            else{
                prev = c;
                cnt = 1;
                ans.push_back(c);
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