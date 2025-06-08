#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> d(n + 1, 0);
        for (auto& query : queries){
            int s = query[0];
            int e = query[1];
            d[s] -= 1;
            d[e + 1] += 1;
        }
        int sub = 0;
        for (int i = 0; i < n; i++){
            sub += d[i];
            if (nums[i] + sub > 0) return false;
        }
        return true;
    }
};

int main(){
    vector<int> nums = {1,0,1};
    vector<vector<int>> queries = {{0,2}};
    // vector<int> nums = {4,3,2,1};
    // vector<vector<int>> queries = {{1,3},{0,2}};
    Solution S;
    cout << S.isZeroArray(nums, queries) << endl;
    return 0;
}