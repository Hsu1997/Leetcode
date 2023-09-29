#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int acc = 0;
        for (int d = 0; d <= 2*k && d < n; d++) acc += nums[d];
        if (k < n) ans[k] = acc / (2*k+1);

        for (int d = k+1; d < n-k; d++){
            acc = acc + nums[d+k] - nums[d-k-1];
            ans[d] = acc / (2 * k + 1);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    Solution S;
    vector<int> ans = S.getAverages(nums, k);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}