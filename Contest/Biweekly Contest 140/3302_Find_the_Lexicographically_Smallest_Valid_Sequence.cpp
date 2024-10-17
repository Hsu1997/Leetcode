#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> last_chance(n, -1);
        for (int i = m-1, j = n-1; i >= 0 && j >= 0; i--){
            if (word1[i] == word2[j]){
                last_chance[j] = i;
                j--;
            }
        }
        // for (int i : last_chance) cout << i << " ";
        // cout << endl;
        int pass = 0;
        vector<int> ans;
        for (int i = 0, j = 0; i < m && j < n; i++){
            if (word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else{
                if (pass == 0 && (j == n-1 || i < last_chance[j+1])){
                    ans.push_back(i);
                    j++, pass++;
                }
                else continue;
            }
        }
        return (ans.size() == n)? ans : vector<int>();
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
    // string word1 = "cdbbcdddddbdddbcdbdbbbccbbc";
    // string word2 = "dbc";
    // string word1 = "babcdz";
    // string word2 = "abcde";
    Solution S;
    vector<int> ans = S.validSequence(word1, word2);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}