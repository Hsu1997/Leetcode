#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) nums[i] %= k;
        vector<long long> ans(k, 0);
        vector<long long> record(k, 0);
        for (int i = 0; i < n; i++){
            int curr = nums[i];
            vector<long long> temp(k, 0);
            for (int j = 0; j < k; j++){
                temp[(curr * j) % k] += record[j];
            }
            temp[curr]++;
            for (int j = 0; j < k; j++) ans[j] += temp[j];
            swap(temp, record);
        }
    return ans;
    }
};

int main(){
    // vector<int> nums = {1,2,3,4,5};
    // int k = 3;
    // vector<int> nums = {1,2,4,8,16,32};
    // int k = 4;
    vector<int> nums = {1,1,2,1,1};
    int k = 2;
    Solution S;
    vector<long long> ans = S.resultArray(nums, k);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}