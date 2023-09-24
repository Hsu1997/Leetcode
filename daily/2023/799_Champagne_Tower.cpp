#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(query_row + 1);
        vector<double> temp(query_row + 1);
        dp[0] = (double)poured;
        for (int i = 1; i <= query_row; i++){
            temp[0] = 0;
            for (int j = 0; j < i; j++){
                temp[j+1] = 0;
                if (dp[j] > 1){
                    temp[j] += (dp[j]-1)/2;
                    temp[j+1] += (dp[j]-1)/2;
                }
                // cout << temp[j] << " ";
            }
            // cout << endl;
            swap(temp, dp);
        }
        return min(dp[query_glass],1.0);
    }
};

int main(){
    // int poured = 1;
    // int poured = 2;
    // int query_row = 1;
    // int query_glass = 1;
    int poured = 100000009;
    int query_row = 33;
    int query_glass = 17;
    Solution S;
    cout << S.champagneTower(poured, query_row, query_glass) << endl;
    return 0;
}