#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dp(int start, vector<int>& memo, vector<int>& arr, int d){
        if (memo[start] != -1) return memo[start];
        int s = max(0, start - d);
        int e = min(int(arr.size()) - 1, start + d);
        int res = 0;
        for (int i = start - 1; i >= max(0, start - d); i--){
            if (arr[i] >= arr[start]) break;
            res = max(res, dp(i, memo, arr, d));
        }
        for (int i = start + 1; i <= min(int(arr.size()) - 1, start + d); i++){
            if (arr[i] >= arr[start]) break;
            res = max(res, dp(i, memo, arr, d));
        }
        memo[start] = res + 1;
        return memo[start];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n, -1);
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, dp(i, memo, arr, d));
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {6,4,14,6,8,13,9,7,10,6,12};
    int d = 2;
    // vector<int> arr = {3,3,3,3,3};
    // int d = 3;
    // vector<int> arr = {7,6,5,4,3,2,1};
    // int d = 1;
    Solution S;
    cout << S.maxJumps(arr, d) << endl;
    return 0;
}