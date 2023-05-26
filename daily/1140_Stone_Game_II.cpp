#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int helper(vector<int>& piles, int people, int start, int m){
        if (start == n) return 0;
        if (dp[people][start][m] != -1) return dp[people][start][m];
        int res;
        int acc = 0;
        if (people == 0){
            res = -1;
            for (int i = 0; i < min(2 * m, n - start); i++){
                acc += piles[start + i];
                res = max(res, acc + helper(piles, 1, start + i + 1, max(m, i + 1)));
            }
        }
        else{
            res = 1000000;
            for (int i = 0; i < min(2 * m, n - start); i++){
                acc += piles[start + i];
                res = min(res, helper(piles, 0, start + i + 1, max(m, i + 1)));
            }
        }
        dp[people][start][m] = res;
        return res;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp = vector(2, vector(n+1, vector(n+1, -1)));
        return helper(piles, 0, 0, 1);
    }
};

int main(){
    vector<int> piles = {2,7,9,4,4};
    Solution S;
    cout << S.stoneGameII(piles) << endl;
    return 0;
}