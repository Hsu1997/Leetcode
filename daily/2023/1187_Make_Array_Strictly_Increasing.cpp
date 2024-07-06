#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int n1 = arr1.size();
        int n2 = 1;
        for (int i = 1; i < arr2.size(); i++) if (arr2[i] != arr2[i-1]) arr2[n2++] = arr2[i];
        arr2.resize(n2);
        // for (auto i : arr2) cout << i << " ";
        // cout << endl;
        vector<vector<int>> dp(n1, vector(n2+1, INT_MAX));
        dp[0][0] = 0;
        for (int j = 1; j < n2+1; j++){
            if (arr1[0] == arr2[j-1]) dp[0][j] = 0;
            else dp[0][j] = 1;
            if (arr1[1] > arr2[j-1]) dp[1][0] = min(dp[1][0], dp[0][j]);
        }
        for (int i = 1; i < n1-1; i++){
            if (arr1[i] > arr1[i-1]) dp[i][0] = min(dp[i][0], dp[i-1][0]);
            int temp = INT_MAX;
            for (int j = 1; j < n2+1; j++){
                if (arr2[j-1] > arr1[i-1]) temp = min(temp, dp[i-1][0]);
                if (temp != INT_MAX) dp[i][j] = temp+1;
                temp = min(temp, dp[i-1][j]);
                if (arr2[j-1] < arr1[i+1]) dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
            }
        }
        if (arr1[n1-1] > arr1[n1-2]) dp[n1-1][0] = min(dp[n1-1][0],dp[n1-2][0]);
        int ans = dp[n1-1][0];
        int temp = INT_MAX;
        for (int j = 1; j < n2+1; j++){
            if (arr2[j-1] > arr1[n1-2]) temp = min(temp, dp[n1-2][0]);
            if (temp != INT_MAX) dp[n1-1][j] = temp+1;
            temp = min(temp, dp[n1-2][j]);
            ans = min(ans, dp[n1-1][j]);
        }
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return (ans == INT_MAX)? -1 : ans;
    }
};

int main(){
    vector<int> arr1 = {1,5,3,6,7};
    vector<int> arr2 = {1,3,2,4};
    // vector<int> arr1 = {1,5,3,6,7};
    // vector<int> arr2 = {4,3,1};
    // vector<int> arr1 = {1,5,3,6,7};
    // vector<int> arr2 = {1,6,3,3};
    Solution S;
    cout << S.makeArrayIncreasing(arr1, arr2) << endl;
    return 0;
}