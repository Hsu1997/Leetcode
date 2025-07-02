#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word, int k) {
        int mod = 1e9 + 7;
        word += '.';
        vector<int> contingous_len;
        int l = 1;
        for (int i = 1; i < word.length(); i++){
            if (word[i] == word[i-1]) l++;
            else{
                contingous_len.push_back(l);
                l = 1;
            }
        }
        long long ans = 1;
        for (int i : contingous_len){
            ans = (ans * i) % mod;
        }
        int n = contingous_len.size();
        if (n >= k) return ans;
        // for (int i : contingous_len) cout << i << " ";
        // cout << endl << endl;
        vector<int> presum(k, 0);
        presum[0] = 1;
        for (int i = 0; i < n; i++){
            int curr_len = contingous_len[i];
            vector<int> curr(k, 0);
            for (int j = 1; j < k; j++){
                // (j - curr_len) ~ (j - 1) = presum[j-1] - presum[j-curr_len-1]
                curr[j] = presum[j-1];
                if (j - curr_len - 1 >= 0) curr[j] -= presum[j - curr_len - 1];
                if (curr[j] < 0) curr[j] += mod;
            }
            presum[0] = curr[0];
            for (int j = 1; j < k; j++) presum[j] = (presum[j-1] + curr[j]) % mod;
        }
        int smaller_than_k_sum = 0;
        for (int i : presum) smaller_than_k_sum = (smaller_than_k_sum + i) % mod;
        ans -= smaller_than_k_sum;
        if (ans < 0) ans += mod;
        return ans;
    }
};

int main(){
    string word = "aabbccdd";
    int k = 7;
    // string word = "aabbccdd";
    // int k = 8;
    // string word = "aaabbb";
    // int k = 3;
    // string word = "wwwwwwwbbbbssssssssvvoooooooqqqqqqqqqvvvvvooooooocccccppppkkkkkkjnddddddbbb";
    // int k = 50;
    // string word = "bbzoggrccukkwwzqdrrhhhkvbbvjwggvvccsdwwiicumoocklyynyyhhcwjssppmmaacceehhtoowkooccekkddppxppzzyyvvll";
    // int k = 80;
    Solution S;
    cout << S.possibleStringCount(word, k) << endl;
    return 0;
}