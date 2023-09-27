#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string ans;

    string removeDuplicateLetters(string s) {
        vector<int> count(26);
        vector<bool> visited(26);
        string ans;

        for (char c : s) count[c-'a']++;
        for (char c : s){
            count[c-'a']--;
            if (!visited[c-'a']){
                while (ans.size() && c < ans.back() && count[ans.back()-'a']) visited[ans.back()-'a'] = false, ans.pop_back();
                visited[c-'a'] = true, ans += c;
            }
        }
        return ans;
    }
};

int main(){
    string s = "bcabc";
    // string s = "cbacdcbc";
    Solution S;
    cout << S.removeDuplicateLetters(s) << endl;
    return 0;
}