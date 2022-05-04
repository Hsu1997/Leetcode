#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> times;
        int ans = 0;
        for (auto i : nums){
            // cout << i << " ";
            if (k % 2 == 0 && i == k / 2){
                times[k / 2]++;
                ans += times[k / 2] / 2;
                times[k / 2] %= 2;
                // cout << "(times=)" << times[k / 2] << " ";
            }
            else{
                if (i <= k / 2){
                    if (times[i] < 0){
                        ans++;
                    }
                    times[i]++;
                }
                else{
                    if (times[k - i] > 0) ans++;
                    times[k - i]--;
                }
            }
            // cout << ans << endl;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    int k = 5;
    // vector<int> nums = {3,1,3,4,3};
    // int k = 6;
    Solution S;
    cout << S.maxOperations(nums, k) << endl;
    return 0;
}