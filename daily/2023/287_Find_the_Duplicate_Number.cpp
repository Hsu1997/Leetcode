#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int head = 0;
        int tail = nums.size()-1;
        while(head < tail){
            int threshold = head + (tail - head) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] <= threshold) count++;
            }
            if (count > threshold) tail = threshold;
            else head = threshold + 1;
        }
        return head;
    }
};

int main(){
    // vector<int> nums = {1,3,4,2,2};
    // vector<int> nums = {3,1,3,4,2};
    vector<int> nums = {2,2,2,2,2};
    Solution S;
    cout << S.findDuplicate(nums) << endl;
    return 0;
}