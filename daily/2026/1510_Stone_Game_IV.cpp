#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> memo;
    bool helper(int n){
        if (memo[n] != 2) return memo[n];
        int res = 0;
        for (int i = 1; i * i <= n; i++){
            if (helper(n - i * i) == 0) return memo[n] = 1;
        }
        return memo[n] = 0;
    }
    bool winnerSquareGame(int n){
        memo = vector(n + 1, 2);
        memo[0] = 0;
        memo[1] = 1;
        return helper(n);
    }
};

int main(){
    int n = 1;
    // int n = 2;
    // int n = 4;
    Solution S;
    cout << S.winnerSquareGame(n) << endl;
    return 0;
}