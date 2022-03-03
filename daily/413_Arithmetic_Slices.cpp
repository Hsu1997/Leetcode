#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // 算出連續的長度後計算有多少 subarrays
        // (n-2) + (n-3) + ... + 1 = 1/2 * (pow(n,2) - 3 * n ) + 1
        if (nums.size() < 3) return 0;
        vector<int>::iterator a,b,c;
        int d, count, accumulate;
        accumulate = 0;
        a = b = c = nums.begin();
        b++;
        c = b+1;
        while(b != nums.end()){
            // cout << "now begin, a = " << *a << ", b = " << *b << ", c = " << *c  << endl;
            d = *b - *a;
            // cout << "distance = " << d << endl;
            while (c != nums.end() && *c - * b == d){
                b++;
                c++;
            }
            // cout << "after while, a = " << *a << ", b = " << *b << ", c = " << *c  << endl;
            count = b - a + 1;
            // cout << "count = " << count << endl;
            if (count >= 3){
                accumulate += (pow(count,2) - 3 * count ) / 2 + 1;
            }
            // cout << "accumaulate = " << accumulate << endl;
            a = b;
            b++;
            if (b != nums.end()) c = b + 1;
        }
        return accumulate;
    }
};

int main(){
    vector<int> nums = {2,4,6,8,1,2,3,4};
    Solution S;
    cout << S.numberOfArithmeticSlices(nums) << endl;
    return 0;
}