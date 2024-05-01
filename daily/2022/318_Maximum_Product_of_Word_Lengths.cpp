#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bitset<26> change_to_int(string s){
        bitset<26> ans;
        for (char c : s) ans[c - 'a'] = 1;
        return ans;
    }

    bool check(bitset<26> a, bitset<26> b){
        for (int i = 0; i < 26; i++) if (a[i] && b[i]) return true;
        return false;
    }

    int maxProduct(vector<string>& words) {
        int ans = 0;
        bitset<26> word[words.size()];
        for (int i = 0; i < words.size(); i++) word[i] = change_to_int(words[i]);
        for (int i = 0; i < words.size(); i++){
            for (int j = 0; j < i; j++){
                if (!check(word[i], word[j])){
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution S;
    cout << S.maxProduct(words) << endl;
    return 0;
}