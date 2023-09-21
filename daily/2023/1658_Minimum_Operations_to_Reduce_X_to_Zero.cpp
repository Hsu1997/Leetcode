#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> accl(n,0);
        vector<int> accr(n,0);
        accl[0] = nums[0];
        accr[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            accl[i] = accl[i-1]+nums[i];
            accr[n-1-i] = accr[n-i]+nums[n-1-i];
        }
        // for (auto i : accl) cout << i << " ";
        // cout << endl;
        // for (auto i : accr) cout << i << " ";
        // cout << endl;
        if (x > accr[0]) return -1;
        if (x == accr[0]) return n;
        int l = 0;
        int r = n-1;
        int ans = INT_MAX;
        while(l < n && accl[l] < x) l++;
        if (accl[l] == x) ans = min(ans, l+1);
        while(r >= 0 && accr[r] < x) r--;
        if (accr[r] == x) ans = min(ans, n-r);
        l--;
        r = n-1;
        while(l >= 0 && r > l){
            // cout << "l = " << accl[l] << ", r = " << accr[r] << endl;
            if (accl[l] + accr[r] > x) l--;
            else if (accl[l] + accr[r] < x) r--;
            else ans = min(ans, l+1+n-r), l++, r--;
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};

int main(){
    // vector<int> nums = {1,1,4,2,3};
    // int x = 5;
    // vector<int> nums = {5,6,7,8,9};
    // int x = 4;
    vector<int> nums = {3,2,20,1,1,3};
    int x = 10;
    Solution S;
    cout << S.minOperations(nums, x) << endl;
    return 0;
}