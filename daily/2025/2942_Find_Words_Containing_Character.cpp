#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        for (int i = 0; i < n; i++){
            string& word = words[i];
            for (char c : word){
                if (c == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"leet","code"};
    char x = 'e';
    // vector<string> words = {"abc","bcd","aaaa","cbc"};
    // char x = 'a';
    // vector<string> words = {"abc","bcd","aaaa","cbc"};
    // char x = 'z';
    Solution S;
    vector<int> ans = S.findWordsContaining(words, x);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}