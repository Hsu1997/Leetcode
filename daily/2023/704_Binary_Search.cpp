#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h = 0;
        int t = nums.size();
        while (h < t){
            int mid = h + (t - h) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) h = mid + 1;
            else t = mid;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution S;
    cout << S.search(nums, target) << endl;
    return 0;
}