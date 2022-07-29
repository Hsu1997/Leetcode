#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        vector c(26,0);
        for (auto i : pattern){
            c[i-'a']++;
        }

        for (string s : words){
            if (s.length() != pattern.length()) continue;

            vector<int> count = c;
            vector<int> p(26,-1);
            vector<int> q(26,-1);

            for (int i = 0; i < s.length(); i++){
                int a = s[i]-'a';
                int b = pattern[i]-'a';

                if (p[a] == -1 && q[b] == -1){
                    p[a] = b;
                    q[b] = a;
                    count[b]--;
                }
                else if (p[a] == b && q[b] == a) count[b]--;
                else break;
            }

            // for (auto i : count) cout << i << " ";
            // cout << endl;
            
            bool get = true;
            for (auto i : count){
                get &= (i == 0);
            }
            if (get) ans.push_back(s);
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    // vector<string> words = {"a","b","c","a"};
    // string pattern = "a";
    Solution S;
    vector<string> ans = S.findAndReplacePattern(words, pattern);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}