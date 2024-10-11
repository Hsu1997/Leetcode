#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = 0;
        vector<int> record = {nums[0]};
        vector<int> index = {0};
        for (int i = 1; i < nums.size(); i++){
            auto it = upper_bound(record.begin(), record.end(), nums[i]);
            if (it == record.end()) ans = i;
            else{
                int idx = it - record.begin();
                if (idx == 0){
                    record.insert(it, nums[i]);
                    index.insert(index.begin(), i);
                }
                else{
                    ans = max(ans, i - index[idx-1]);
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {6,0,8,2,1,5};
    // vector<int> nums = {9,8,1,0,1,9,4,0,4,1};
    Solution S;
    cout << S.maxWidthRamp(nums) << endl;
    return 0;
}