#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, double>> dp;

    double subprob(int a, int b){
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (dp[a].count(b)) return dp[a][b];
        dp[a][b] = (subprob(a-4,b) + subprob(a-3,b-1) + subprob(a-2,b-2) + subprob(a-1,b-3)) / 4;
        return dp[a][b];
    }

    double soupServings(int n) {
        int m = ceil(n / 25.0);
        for (int i = 1; i < m; i++){
            if (subprob(i,i) > 1 - 1e-5) return 1; 
        }
        return subprob(m,m);
    }
};

int main(){
    // int n = 50;
    int n = 100;
    Solution S;
    cout << S.soupServings(n) << endl;
    return 0;
}