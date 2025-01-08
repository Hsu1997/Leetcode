#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool is_prefix(string& pattern, string& content){
        int m = pattern.length();
        int n = content.length();
        if (m > n) return false;
        for (int i = 0; i < m; i++) if (pattern[i] != content[i]) return false;
        return true;
    }
    bool is_suffix(string& pattern, string& content){
        int m = pattern.length();
        int n = content.length();
        if (m > n) return false;
        for (int i = 0; i < m; i++) if (pattern[i] != content[n-m+i]) return false;
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (is_prefix(words[i], words[j]) && is_suffix(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"a","aba","ababa","aa"};
    // vector<string> words = {"pa","papa","ma","mama"};
    // vector<string> words = {"abab","ab"};
    Solution S;
    cout << S.countPrefixSuffixPairs(words) << endl;
    return 0;
}