#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dp(vector<vector<int>>& memo, vector<int>& piles, int start, int end){
        if (start > end) return 0;
        if (memo[start][end] != INT_MIN) return memo[start][end];
        if (start == end) return piles[start];
        return memo[start][end] = max(piles[start] - dp(memo, piles, start + 1, end), piles[end] - dp(memo, piles, start, end - 1));
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        dp(memo, piles, 0, n - 1);
        return memo[0][n-1] > 0;
    }
};

int main(){
    vector<int> piles = {5,3,4,5};
    // vector<int> piles = {3,7,2,3};
    Solution S;
    cout << S.stoneGame(piles) << endl;
    return 0;
}