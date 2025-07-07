#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int,int> cnt1;
    unordered_map<int,int> cnt2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int i : nums1) cnt1[i]++;
        for (int i : nums2) cnt2[i]++;
    }
    
    void add(int index, int val) {
        cnt2[nums2[index]]--;
        nums2[index] += val;
        cnt2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto& [v, c] : cnt1){
            ans += cnt2[tot - v] * c;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

 int main(){
    vector<int> nums1 = {1,1,2,2,2,3};
    vector<int> nums2 = {1,4,5,2,5,4};
    FindSumPairs obj(nums1, nums2);
    cout << obj.count(7) << " ";
    obj.add(3,2);
    cout << obj.count(8) << " ";
    cout << obj.count(4) << " ";
    obj.add(0,1);
    obj.add(1,1);
    cout << obj.count(7) << endl;
 }