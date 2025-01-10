#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> universal(26, 0);
        for (string s : words2){
            vector<int> count(26, 0);
            for (char c : s){
                count[c-'a']++;
            }
            for (int i = 0; i < 26; i++) universal[i] = max(universal[i], count[i]);
        }
        vector<string> ans;
        for (string s : words1){
            vector<int> count(26, 0);
            for (char c : s) count[c-'a']++;
            bool is_universal = true;
            for (int i = 0; i < 26; i++){
                if (count[i] < universal[i]){
                    is_universal = false;
                    break;
                }
            }
            if (is_universal) ans.push_back(s);
        }
        return ans;
    }
};

int main(){
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e","o"};
    // vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    // vector<string> words2 = {"l","e"};
    Solution S;
    vector<string> ans = S.wordSubsets(words1, words2);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}