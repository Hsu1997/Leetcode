#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ans = 1;

    int longestStrChain(vector<string>& words) {
        
        vector<unordered_set<string>> record(17);
        for (string i : words) record[i.size()].insert(i);

        // for (int i = 1; i < 18; i++){
        //     cout << i << ": ";
        //     for (string j : record[i]) cout << j << " ";
        //     cout << endl;
        // }

        unordered_map<string, int> dp;

        for (int i = 16; i > 0; i--){
            if (record[i-1].empty()) continue;
            for (auto j : record[i]){
                int now_length = dp[j]? dp[j]:1;
                for (int k = 0; k < j.size(); k++){
                    string predecessor = j.substr(0,k) + j.substr(k+1);
                    int predecessor_length = dp[predecessor]? dp[predecessor]:1;
                    if (record[i-1].find(predecessor) != record[i-1].end() && now_length >= predecessor_length){
                        dp[predecessor] = now_length + 1;
                        ans = max(ans, dp[predecessor]);
                    }
                }
            }
        }
        
        return ans;
    }
};

int main(){
    // vector<string> words = {"a","b","ba","bca","bda","bdca"};
    // vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    vector<string> words = {"abcd","dbqca"};
    // vector<string> words = {"a","b","ba","abc","abd","bdca"};
    // vector<string> words = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
    Solution S;
    cout << S.longestStrChain(words) << endl;
    return 0;
}


// "gr","ks"
// "kss","gru"
// "czvh","gruj","kssq",
// "ksqsq","grukj","zczvh",
// "zcpzvh","grukmj","ksqvsq",
// "zczpzvh","grukkmj","ksqvsyq"
// "zczpzvhx",
// "zczpzvdhx",
// "zczpzfvdhx",




