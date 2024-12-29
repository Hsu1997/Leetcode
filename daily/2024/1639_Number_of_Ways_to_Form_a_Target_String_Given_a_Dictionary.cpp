#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n, m, k;
    long mod = 1e9 + 7;
    vector<vector<int>> memo;
    vector<vector<int>> freq;

    long helper(string& target, int i, int j){
        if (j == m) return 1;
        if (i == n) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        char target_char = target[j];
        int take = freq[i][target_char - 'a'] * helper(target, i+1, j+1) % mod;
        int not_take = helper(target, i+1, j);
        int total_count = (take + not_take) % mod;
        return memo[i][j] = total_count;
    }

    int numWays(vector<string>& words, string target) {
        n = words[0].size();
        m = target.size();
        k = words.size();
        if (m > n) return 0;

        memo = vector<vector<int>>(n, vector<int>(m, -1));
        freq = vector<vector<int>>(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++){
            for (int l = 0; l < k; l++){
                freq[i][words[l][i] - 'a']++;
            }
        }
        return helper(target, 0, 0);
    }
};

int main(){
    vector<string> words = {"acca","bbbb","caca"};
    string target = "aba";
    // vector<string> words = {"abba","baab"};
    // string target = "bab";
    Solution S;
    cout << S.numWays(words, target) << endl;
    return 0;
}