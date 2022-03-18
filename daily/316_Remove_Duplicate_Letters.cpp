#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        int n = s.size();
        int amount[26] = {0};
        int visited[26] = {0};

        for (int i = 0; i < n; i++){
            amount[s[i]-'a']++;
        }

        for (int i = 0; i < n; i++){
            amount[s[i]-'a']--;
            if (visited[s[i]-'a'] == 0){
                while (ans.size() > 0 && s[i] < ans.back() && amount[ans.back()-'a'] > 0){
                    visited[ans.back()-'a'] = 0;
                    ans.pop_back();
                }
                visited[s[i]-'a'] = 1;
                ans += s[i];
            }
        }
        return ans;
    }
};

int main(){
    string s = "cdadabcc";
    // string s = "leetcode";
    Solution S;
    cout << S.removeDuplicateLetters(s) << endl;
    return 0;
}