#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26, 0);
        vector<bool> visited(26, false);
        for (char c : s) cnt[c - 'a']++;
        string ans;
        for (char c : s){
            if (!visited[c - 'a']){
                while(!ans.empty() && c < ans.back() && cnt[ans.back() - 'a'] > 0){
                    visited[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                visited[c - 'a'] = true;
                ans.push_back(c);
            }
            cnt[c - 'a']--;
        }
        return ans;
    }
};

int main(){
    string s = "bcabc";
    // string s = "cbacdcbc";
    // string s = "asexijes";
    // string s = "wamecwcnenesdsdsdsds";
    // string s = "wxeijjiehuxasenfmkwsesmndsndsnnndsnsdssdsdss";
    // string s = "xweirnwexdnreujk";
    // string s = "cbaacabcaaccaacababa";
    Solution S;
    cout << S.smallestSubsequence(s) << endl;
    return 0;
}