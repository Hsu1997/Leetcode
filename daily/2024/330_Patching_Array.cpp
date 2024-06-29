#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long now_complete = 1;
        int ans = 0;
        if (nums[0] != 1){
            nums.insert(nums.begin(), 1);
            ans++;
        }
        for (int i = 1; i < nums.size(); i++){
            int look = nums[i];
            // cout << "now look at " << look << endl;
            if (now_complete >= n) return ans;
            if (look == now_complete + 1) now_complete = now_complete * 2 + 1;
            else{
                // cout << "in while" << endl;
                while(look > now_complete + 1){
                    now_complete = now_complete * 2 + 1;
                    ans++;
                    // cout << "can complete " << now_complete << ", ans = " << ans << endl;
                    if (now_complete >= n) return ans;
                }
                // cout << "out while" << endl;
                now_complete += look;
            }
            // cout << "can complete " << now_complete << ", ans = " << ans << endl;
        }
        while(now_complete < n){
            // cout << "can complete " << now_complete << ", ans = " << ans << endl;
            now_complete = now_complete * 2 + 1;
            ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3};
    int n = 6;
    // vector<int> nums = {1,5,10};
    // int n = 20;
    // vector<int> nums = {1,2,2};
    // int n = 5;
    // vector<int> nums = {1,2,31,33};
    // int n = 2147483647;
    // vector<int> nums = {1,2,32};
    // int n = 2147483647;
    Solution S;
    cout << S.minPatches(nums, n) << endl;
    return 0;
}