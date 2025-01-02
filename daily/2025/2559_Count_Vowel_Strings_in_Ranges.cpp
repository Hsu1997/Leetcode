#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> acc(n, 0);
        acc[0] = is_vowel(words[0][0]) && is_vowel(words[0].back());
        for (int i = 1; i < n; i++) acc[i] = acc[i-1] + (is_vowel(words[i][0]) && is_vowel(words[i].back()));
        int q = queries.size();
        vector<int> ans(q, 0);
        for (int query = 0; query < q; query++){
            int start = queries[query][0];
            int end = queries[query][1];
            if (start == 0) ans[query] = acc[end];
            else ans[query] = acc[end] - acc[start-1];
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
    // vector<string> words = {"a","e","i"};
    // vector<vector<int>> queries = {{0,2},{0,1},{2,2}};
    Solution S;
    vector<int> ans = S.vowelStrings(words, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}