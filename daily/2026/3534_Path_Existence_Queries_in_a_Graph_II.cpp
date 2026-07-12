#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        unordered_map<int,int> transidx;
        for (int i = 0; i < n; i++){
            transidx[arr[i].second] = i;
        }
        int k = 1;
        int temp = 1;
        while(temp < n){
            k++;
            temp <<= 1;
        }
        vector<vector<int>> dp(n, vector<int>(k));
        int farrest = 0;
        for (int i = 0; i < n; i++){
            farrest = max(farrest, i);
            while(farrest < n - 1 && arr[i].first + maxDiff >= arr[farrest + 1].first) farrest++;
            dp[i][0] = farrest;
        }
        for (int j = 1; j < k; j++){
            for (int i = 0; i < n; i++){
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++){
            int x = transidx[queries[i][0]];
            int y = transidx[queries[i][1]];
            if (x > y) swap(x, y);
            if (dp[x][k-1] < y) ans[i] = -1;
            else{
                int curr = x;
                int steps = 0;
                for (int j = k - 1; j >= 0; j--){
                    if (dp[curr][j] < y){
                        curr = dp[curr][j];
                        steps += 1 << j;
                    }
                }
                ans[i] = steps + (curr < y);
            }
        }
        return ans;
    }
};

int main(){
    int n = 5;
    vector<int> nums = {1,8,3,4,2};
    int maxDiff = 3;
    vector<vector<int>> queries = {{0,3},{2,4}};
    // int n = 5;
    // vector<int> nums = {5,3,1,9,10};
    // int maxDiff = 2;
    // vector<vector<int>> queries = {{0,1},{0,2},{2,3},{4,3}};
    // int n = 3;
    // vector<int> nums = {3,6,1};
    // int maxDiff = 1;
    // vector<vector<int>> queries = {{0,0},{0,1},{1,2}};
    Solution S;
    vector<int> ans = S.pathExistenceQueries(n, nums, maxDiff, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}