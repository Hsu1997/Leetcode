#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> right(m, -1);
        int i = n - 1;
        for (int j = m - 1; j >= 0; j--){
            while(i >= 0 && word1[i] != word2[j]) i--;
            if (i < 0) break;
            right[j] = i;
            i--;
        }
        vector<int> ans;
        bool changed = false;
        int j = 0;
        for (int i = 0; i < n && j < m; i++){
            if (word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else{
                if (!changed && (j == m - 1 || i < right[j + 1])){
                    ans.push_back(i);
                    j++;
                    changed = true;
                }
            }
        }
        if (j == m) return ans;
        return {};
    }
};

int main(){
    string word1 = "vbcca";
    string word2 = "abc";
    // string word1 = "bacdc";
    // string word2 = "abc";
    // string word1 = "aaaaaa";
    // string word2 = "aaabc";
    // string word1 = "abc";
    // string word2 = "ab";
    // string word1 = "ghhgghhhhhh";
    // string word2 = "gg";
    // string word1 = "abfdfeeaddccbbddfddcddaebdecaaebbebceaddcbbefdfebceefffeffeeeefeffeeefeefffreeeeffeeefeeffeeffeeeffeccbabbdcafdebdccfabbbcabfbeaecbfabfebaeedcabdceded";
    // string word2 = "eefffeffeeeefeffeeefeefffeeeeeffeeefeeffeeffeeeffe";
    Solution S;
    vector<int> ans = S.validSequence(word1, word2);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}