#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n < m) swap(m, n);
        vector<int> dp(m, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = 1; j < m; j++){
                dp[j] += dp[j-1];
            }
        }
        return dp.back();
    }
};

int main(){
    int m = 3;
    int n = 2;
    Solution S;
    cout << S.uniquePaths(m, n) << endl;
    return 0;
}