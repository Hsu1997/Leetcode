#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd = true;
        bool even = true;
        int minOdd = INT_MAX;
        int minEven = INT_MAX;
        for (int i : nums1){
            if (i % 2) minOdd = min(minOdd, i);
            else minEven = min(minEven, i);
        }
        for (int i : nums1){
            bool currOdd = (i % 2 == 1) || (i > minOdd);
            bool currEven = (i % 2 == 0) || (i > minOdd);
            odd &= currOdd;
            even &= currEven;
            if (!odd && !even) return false;
        }
        return true;
    }
};

int main(){
    vector<int> nums1 = {1,4,7};
    // vector<int> nums1 = {2,3};
    // vector<int> nums1 = {4,6};
    Solution S;
    cout << S.uniformArray(nums1) << endl;
    return 0;
}