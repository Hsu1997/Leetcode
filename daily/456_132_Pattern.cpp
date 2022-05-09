#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int second = numeric_limits<int>::min();
        stack<int> temp;
        for (int i = nums.size()-1; i >= 0; i--){
            if (nums[i] < second) return true;
            if (temp.size() > 0 && nums[i] == temp.top()) continue;
            while (temp.size() > 0 && nums[i] > temp.top()){
                second = temp.top();
                temp.pop();
            }
            temp.push(nums[i]);
        }
        return false;
    }
};

int main(){
    vector<int> nums = {5,8,3,6,9,2};
    // vector<int> nums = {1,2,3,4,-4,-3,-5,-1};
    // vector<int> nums = {1,3,2,4,5,6,7,8,9,10};
    // vector<int> nums = {3,1,4,2};
    Solution S;
    cout << S.find132pattern(nums) << endl;
    return 0;
}