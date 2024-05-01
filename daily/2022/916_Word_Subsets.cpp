#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> limit(26,0);
        for (string i : words2){
            vector<int> temp(26,0);
            for (auto j : i){
                temp[j-'a']++;
            }
            for (int k = 0; k < 26; k++) limit[k] = max(limit[k], temp[k]);
        }

        vector<string> ans;
        for (string w : words1){
            vector<int> temp(26,0);
            for (auto j : w) temp[j-'a']++;
            for (int k = 0; k < 26; k++){
                if (temp[k] < limit[k]) goto search;
            }
            ans.push_back(w);
            search : ;
        }
        
        return ans;
    }
};

int main(){
    // vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    // vector<string> words2 = {"e","o"};
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"lo","eo"};

    Solution S;
    vector<string> ans = S.wordSubsets(words1, words2);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}