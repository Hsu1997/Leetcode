#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        vector<vector<int>> dp(n, vector<int>(d, 3e5+1));
        vector<vector<int>> record(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++){
            int temp = jobDifficulty[i];
            for (int j = i; j < n; j++){
                temp = max(temp, jobDifficulty[j]);
                record[i][j] = temp;
            }
        }
        // for (auto i : record){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        for (int i = 0; i < n; i++) dp[i][0] = record[0][i];

        for(int days = 1; days < d; days++){
            for (int i = 0; i < n; i++){
                int temp = 3e5+1;
                for (int last_day = 1; last_day <= i - days + 1; last_day++){
                    temp = min(temp, dp[i-last_day][days-1] + record[i-last_day+1][i]);
                }
                dp[i][days] = temp;
            }
        }

        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        
        return dp[n-1][d-1];
    }
};

int main(){
    // vector<int> jobDifficulty = {6,5,4,3,2,1};
    // int d = 2;
    // vector<int> jobDifficulty = {9,9,9};
    // int d = 4;
    // vector<int> jobDifficulty = {1,1,1};
    // int d = 3;
    vector<int> jobDifficulty = {143,446,351,170,117,963,785,76,139,772,452,743,23,767,564,872,922,532,957,945,203,615,843,909,458,320,290,235,174,814,414,669,422,769,781,721,523,94,100,464,484,562,941};
    int d = 5;

    Solution S;
    cout << S.minDifficulty(jobDifficulty, d) << endl;
    return 0;
}