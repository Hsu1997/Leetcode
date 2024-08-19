#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n;
    int minSteps(int n) {
        if (n == 1) return 0;
        this->n = n;
        // {accumulate count, on board amount}
        vector<vector<int>> memo(n + 1, vector<int>(n / 2 + 1, 0));
        return 1 + helper(memo, 1, 1);
    }

    int helper(vector<vector<int>>& memo, int acc, int on_board){
        if (acc == n) return 0;
        if (acc > n) return 1000;
        if (memo[acc][on_board] != 0) return memo[acc][on_board];
        int op1 = 1 + helper(memo, acc + on_board, on_board);
        int op2 = 2 + helper(memo, 2 * acc, acc);
        memo[acc][on_board] = min(op1, op2);
        return memo[acc][on_board];
    }
};

int main(){
    // int n = 3;
    // int n = 1;
    // int n = 1000;
    int n = 997;
    Solution S;
    cout << S.minSteps(n) << endl;
    return 0;
}