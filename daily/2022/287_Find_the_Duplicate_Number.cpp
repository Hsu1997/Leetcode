#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int threshold){
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] <= threshold) count++;
            if (count > threshold) return true;
        }
        return false;
    }

    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) /2;
            if (check(nums, mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         while(nums[0] != nums[nums[0]]){
//             swap(nums[0], nums[nums[0]]);
//         }
//         return nums[0];
//     }
// };

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {

//         // Find the intersection point of the two runners.
//         int tortoise = nums[0];
//         int hare = nums[0];

//         do {
//             tortoise = nums[tortoise];
//             hare = nums[nums[hare]];
//         } while (tortoise != hare);

//         // Find the "entrance" to the cycle.
//         tortoise = nums[0];
//         while (tortoise != hare) {
//             tortoise = nums[tortoise];
//             hare = nums[hare];
//         }

//         return hare;
//     }
// };

int main(){
    vector<int> nums = {2,2,2,2,2};
    Solution S;
    cout << S.findDuplicate(nums) << endl;
}