#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int acc = 0;
        int k = 0;
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++){
            while(acc + diff[i] < nums[i]){
                if (k == queries.size()) return -1;
                int start = queries[k][0];
                int end = queries[k][1];
                int val = queries[k][2];
                if (end >= i){
                        diff[max(start, i)] += val;
                        diff[end + 1] -= val;
                }
                k++;
            }
            acc += diff[i];
        }
        return k;
    }
};

// class Solution {
// public:
//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         if (can_be_zero(nums, queries, -1)) return 0;
//         if (!can_be_zero(nums, queries, queries.size() - 1)) return -1;
//         int left = 0;
//         int right = queries.size() - 1;
//         int ans = INT_MAX;
//         while(left <= right){
//             int mid = left + (right - left);
//             if (can_be_zero(nums, queries, mid)){
//                 ans = min(ans, mid);
//                 right = mid - 1;
//             }
//             else left = mid + 1;
//         }
//         return ans + 1;
//     }
//     bool can_be_zero(vector<int>& nums, vector<vector<int>>& queries, int k){
//         int n = nums.size();
//         vector<int> added(n + 1, 0);
//         for (int i = 0; i <= k; i++){
//             int start = queries[i][0];
//             int end = queries[i][1];
//             int val = queries[i][2];
//             added[start] += val;
//             added[end + 1] -= val;
//         }
//         int acc = 0;
//         for (int i = 0; i < n; i++){
//             acc += added[i];
//             if (nums[i] > acc) return false;
//         }
//         return true;
//     }
// };

int main(){
    vector<int> nums = {2,0,2};
    vector<vector<int>> queries = {{0,2,1},{0,2,1},{1,1,3}};
    // vector<int> nums = {4,3,2,1};
    // vector<vector<int>> queries = {{1,3,2},{0,2,1}};
    // vector<int> nums = {0};
    // vector<vector<int>> queries = {{0,0,2},{0,0,4},{0,0,4},{0,0,3},{0,0,5}};
    Solution S;
    cout << S.minZeroArray(nums, queries) << endl;
    return 0;
}