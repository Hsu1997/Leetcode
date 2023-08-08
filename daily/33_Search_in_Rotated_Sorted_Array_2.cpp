#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int diff;
    int n;

    int find_min(vector<int>& nums){
        if (nums.front() < nums.back()) return 0;
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if (nums[mid] > nums[r]) l = mid+1;
            else r = mid;
        }
        return l;
    }
    int transfer(int pos){
        return (pos + diff) % n;
    }
    int search(vector<int>& nums, int target) {
        n = nums.size();
        diff = find_min(nums);
        // cout << diff << endl;
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int temp = nums[transfer(mid)];
            if (temp == target) return transfer(mid);
            if (temp > target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    // int target = 3;
    // vector<int> nums = {1};
    // int target = 0;
    Solution S;
    cout << S.search(nums, target) << endl;
    return 0;
}