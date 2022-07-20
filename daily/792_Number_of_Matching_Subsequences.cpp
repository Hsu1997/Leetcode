#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        vector<vector<const char*>> waiting(27);

        for (auto &i : words) waiting[i[0]-'a'+1].push_back(i.c_str());
        for (char i : s) {
            vector<const char*> temp = waiting[i-'a'+1];
            waiting[i-'a'+1].clear();
            for (auto it : temp){
                it++;
                if (*it == 0) ans++;
                else waiting[(*it)-'a'+1].push_back(it);
            }
        }

        // for (auto i : waiting){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        return ans;
    }
};

int main(){
    // string s = "abcde";
    // vector<string> words = {"a","bb","acd","ace"};
    string s = "dsahjpjauf";
    vector<string> words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    Solution S;
    cout << S.numMatchingSubseq(s, words) << endl;
    return 0;
}