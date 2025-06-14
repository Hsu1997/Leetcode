#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string nums = to_string(num);
        int n = nums.length();
        int i = 0;
        while(i < n && nums[i] == '9') i++;
        if (i < n){
            char c = nums[i];
            for (int idx = i; idx < n; idx++){
                if (nums[idx] == c) nums[idx] = '9';
            }
        }
        int M = stoi(nums);
        nums = to_string(num);
        char c = nums[0];
        for (int idx = 0; idx < n; idx++){
            if (nums[idx] == c) nums[idx] = '0';
        }
        int m = stoi(nums);
        return M - m;
    }
};

int main(){
    int num = 11891;
    // int num = 90;
    Solution S;
    cout << S.minMaxDifference(num) << endl;
    return 0;
}