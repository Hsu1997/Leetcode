#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            int mid = i + (j - i) / 2;
            if (nums[mid] < nums[j]) j = mid;
            else i = mid + 1;
            // cout << nums[i] << " " << nums[mid] << " " << nums[j] << endl;
        }
        // ith palce is the smallest number now
        int rotation = i;
        i = 0;
        j = nums.size() - 1;
        while(i <= j){
            int mid = i + (j - i) / 2;
            int real_mid = (mid + rotation) % nums.size();
            if (nums[real_mid] == target) return real_mid;
            if (nums[real_mid] < target) i = mid + 1;
            if (nums[real_mid] > target) j = mid - 1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    Solution S;
    cout << S.search(nums, target) << endl;
    return 0;
}