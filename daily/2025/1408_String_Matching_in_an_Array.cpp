#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> construct_LPS(string& pattern){
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0;
        for (int i = 1; i < m; i++){
            while(len > 0 && pattern[i] != pattern[len]) len = lps[len-1];
            if (pattern[i] == pattern[len]) len++;
            lps[i] = len;
        }
        return lps;
    }

    bool KMP(string& pattern, string& content){
        // if (pattern.length() > content.length()) return false;
        int m = pattern.length();
        int n = content.length();
        vector<int> lps = construct_LPS(pattern);
        int j = 0;
        for (int i = 0; i < n; i++){
            while(j > 0 && pattern[j] != content[i]) j = lps[j-1];
            if (pattern[j] == content[i]) j++;
            if (j == m){
                return true;
                j = lps[j-1];
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& a, string& b){return a.length() < b.length();});
        vector<string> ans;
        for (int i = 0; i < n; i++){
            for (int j = n-1; j > i; j--){
                // if (i == j) continue;
                if (KMP(words[i], words[j])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"mass","as","hero","superhero"};
    // vector<string> words = {"leetcode","et","code"};
    // vector<string> words = {"blue","green","bu"};
    // vector<string> words = {"leetcoder","leetcode","od","hamlet","am"};
    // vector<string> words = {"eeeet","eeet"};
    Solution S;
    vector<string> ans = S.stringMatching(words);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}