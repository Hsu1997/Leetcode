#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

int main(){
    vector<int> nums1 = {2,3};
    // vector<int> nums1 = {4,6};
    Solution S;
    cout << S.uniformArray(nums1) << endl;
    return 0;
}