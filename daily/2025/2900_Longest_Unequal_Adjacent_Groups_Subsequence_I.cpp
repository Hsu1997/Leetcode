#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> starting_zero;
        vector<string> starting_one;
        int n = words.size();
        for (int i = 0; i < n; i++){
            if (groups[i] % 2 == 0){
                if (starting_zero.size() % 2 == 0) starting_zero.push_back(words[i]);
                if (starting_one.size() % 2 == 1) starting_one.push_back(words[i]);
            }
            else{
                if (starting_zero.size() % 2 == 1) starting_zero.push_back(words[i]);
                if (starting_one.size() % 2 == 0) starting_one.push_back(words[i]);
            }
        }
        return (starting_zero.size() > starting_one.size())? starting_zero : starting_one;
    }
};

int main(){
    vector<string> words = {"e","a","b"};
    vector<int> groups = {0,0,1};
    // vector<string> words = {"a","b","c","d"};
    // vector<int> groups = {1,0,1,1};
    Solution S;
    vector<string> ans = S.getLongestSubsequence(words, groups);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}