#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bit_set(int n){
        int count = 0;
        while(n){
            if (n % 2) count++;
            n /= 2;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        int prev_m = 0;
        int curr_m = 0;
        int temp_count = 0;
        for (int i : nums){
            int c = bit_set(i);
            if (c == temp_count){
                curr_m = max(curr_m ,i);
            }
            else{
                temp_count = c;
                prev_m = curr_m;
                curr_m = i;
            }
            if (i < prev_m) return false;
        }
        return true;
    }
};

int main(){
    vector<int> nums = {8,4,2,30,15};
    // vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {3,16,8,4,2};
    // vector<int> nums = {20,16};
    Solution S;
    cout << S.canSortArray(nums) << endl;
    return 0;
}