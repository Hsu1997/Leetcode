#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int maxv = 0;
        int minv = 1001;
        for (int i : nums){
            maxv = max(maxv, i);
            minv = min(minv, i);
        }
        return gcd(maxv, minv);
    }
};

int main(){
    vector<int> nums = {2,5,6,9,10};
    // vector<int> nums = {7,5,6,8,3};
    // vector<int> nums = {3,3};
    Solution S;
    cout << S.findGCD(nums) << endl;
    return 0;
}