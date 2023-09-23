#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        vector<unordered_set<string>> m(17);
        for (string s : words) m[s.length()].insert(s);
        unordered_map<string,int> c;
        for (int i = 16; i > 0; i--){
            for (string s : m[i]){
                int now_length = (c[s])? c[s] : 1;
                for (int k = 0; k < s.length(); k++){
                    string predecessor = s.substr(0,k) + s.substr(k+1);
                    if (m[i-1].count(predecessor) && now_length >= c[predecessor]){
                        c[predecessor] = now_length + 1;
                        ans = max(ans, c[predecessor]);
                    }

                }
            }
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    // vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    // vector<string> words = {"abcd","dbqca"};
    Solution S;
    cout << S.longestStrChain(words) << endl;
    return 0;
}