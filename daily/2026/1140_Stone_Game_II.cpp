#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dp(int n, vector<int>& piles, vector<vector<int>>& memo, int start, int M){
        if (start >= n) return 0;
        if (memo[start][M] != INT_MIN) return memo[start][M];
        int curr = 0;
        int currAns = INT_MIN;
        for (int i = start; i < min(start + 2 * M, n); i++){
            curr += piles[i];
            currAns = max(currAns, curr - dp(n, piles, memo, i + 1, max(M, i - start + 1)));
        }
        return memo[start][M] = currAns;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, INT_MIN));
        int total = 0;
        for (int i : piles) total += i;
        int diff = dp(n, piles, memo, 0, 1);
        return (total + diff) / 2;
    }
};

int main(){
    vector<int> piles = {2,7,9,4,4};
    // vector<int> piles = {1,2,3,4,5,100};
    Solution S;
    cout << S.stoneGameII(piles) << endl;
    return 0;
}