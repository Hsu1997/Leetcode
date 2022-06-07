#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) nums1 = nums2;
        if (n == 0) return;
        vector<int> n1(m, 0);
        for (int i = 0; i < m; i++) n1[i] = nums1[i];
        vector<int>::iterator ptr1 = n1.begin();
        vector<int>::iterator ptr2 = nums2.begin();
        int i;
        for (i = 0; i < m+n; i++){
            if (ptr1 == n1.end() || ptr2 == nums2.end()) break;
            if (*ptr1 <= *ptr2){
                nums1[i] = *ptr1;
                ptr1++;
            }
            else{
                nums1[i] = *ptr2;
                ptr2++;
            }
        }
        while(ptr1 != n1.end()){
            nums1[i] = *ptr1;
            i++, ptr1++;
        }
        while(ptr2 != nums2.end()){
            nums1[i] = *ptr2;
            i++, ptr2++;
        }
    }
};

int main(){
    vector<int> nums1 = {1};
    vector<int> nums2 = {};
    int m = 1;
    int n = 0;
    Solution S;
    S.merge(nums1, m, nums2, n);
    for (auto i : nums1) cout << i << " ";
    cout << endl;
    return 0;
}