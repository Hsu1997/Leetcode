#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 3) return true;

        bool toleration = false;
        int pre2 = nums[0];
        int pre = nums[1];
        if (nums[0] > nums[1]){
            toleration = true;
            pre2 = pre;
        }

        for (int i = 2; i < nums.size(); i++){
            int now = nums[i];
            if (now >= pre) pre2 = pre, pre = now;
            else{
                if (!toleration){
                    toleration = true;
                    if (now < pre2) continue;
                    else pre = min(now, pre);
                }
                else return false;
            }
        }
        return true;
    }
};

int main(){
    // vector<int> nums = {3,4,2,3};
    vector<int> nums = {-1,4,2,3};
    Solution S;
    cout << S.checkPossibility(nums) << endl;
    return 0;
}