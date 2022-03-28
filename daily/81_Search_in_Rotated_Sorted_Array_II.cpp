#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        int rotation = -1;
        while(i < j){
            int mid = i + (j  - i) / 2;
            if (nums[i] == nums[j] && nums[i] == nums[mid]){
                if (nums[i] == target) return true;
                // cout << "special";
                for (int k = i+1; k != j; ++k%=nums.size()){
                    if (nums[k] != nums[i]){
                        rotation = k;
                        break;
                    }
                }
                if (rotation == -1 && nums[i] != target) return false;
                if (nums[rotation] > nums[i]) rotation++;
                // cout << ", rotation = " << rotation << endl;
                break;
            }
            if (nums[mid] <= nums[j]) j = mid;
            else i = mid + 1;
            rotation = i;

            for (int k = i; k != j; ++k%=nums.size()) cout << nums[k] << " ";
            cout << nums[j] << endl;
        }
        
        
        // cout << "rotation = " << rotation << endl;
        i = 0; j = nums.size() - 1;
        while(i <= j){
            int mid = i + (j - i) / 2;
            int real_mid = (mid + rotation) % nums.size();
            if (nums[real_mid] == target) return 1;
            if (nums[real_mid] < target) i = mid + 1;
            if (nums[real_mid] > target) j = mid - 1;
            
        }
        return false;
    }
};

int main(){
    // vector<int> nums = {2,5,6,0,0,1,2};
    // vector<int> nums = {1,0,0,1,1};
    // vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    vector<int> nums = {1,1};
    int target = 1;
    Solution S;
    cout << S.search(nums, target) << endl;
    return 0;
}