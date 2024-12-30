#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high+1, 0);
        memo[0] = 1;
        for (int curr_len = 1; curr_len <= high; curr_len++){
            int curr_count = 0;
            if (curr_len - zero >= 0) curr_count += memo[curr_len - zero];
            if (curr_len - one >= 0) curr_count += memo[curr_len - one];
            curr_count %= mod;
            memo[curr_len] = curr_count;
        }
        int ans = 0;
        for (int i = low; i <= high; i++){
            ans = (ans + memo[i]) % mod;
        }
        return ans;
    }
};

int main(){
    int low = 3;
    int high = 3;
    int zero = 1;
    int one = 1;
    // int low = 2;
    // int high = 3;
    // int zero = 1;
    // int one = 2;
    Solution S;
    cout << S.countGoodStrings(low, high, zero, one) << endl;
    return 0;
}