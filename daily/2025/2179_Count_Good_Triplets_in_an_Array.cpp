#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class BinaryIndexTree{
public:
    int n;
    vector<int> tree;
    BinaryIndexTree(vector<int>& nums){
        n = nums.size();
        tree = vector<int>(n+1, 0);
        for (int i = 0; i < n; i++) update(i, nums[i]);
    }
    void update(int pos, int val){
        pos++;
        while(pos <= n){
            tree[pos] += val;
            pos += pos & (-pos);
        }
    }
    int query(int pos){
        pos++;
        int ans = 0;
        while(pos > 0){
            ans += tree[pos];
            pos -= pos & (-pos);
        }
        return ans;
    }
    int query_range(int start, int end){
        return query(end) - query(start - 1);
    }

};

class Solution {
public:
    vector<int> find_same_element_of_range(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<int> mapping(n);
        for (int i = 0; i < n; i++) mapping[nums2[i]] = i;
        vector<int> zero(n, 0);
        BinaryIndexTree BIT(zero);
        vector<int> same_element_after_pos(n, 0);
        for (int i = n - 1; i >= 0; i--){
            int curr_element = nums1[i];
            int nums2_pos = mapping[curr_element];
            same_element_after_pos[i] = BIT.query_range(nums2_pos, n - 1);
            BIT.update(nums2_pos, 1);
        }
        // for (auto i : nums1) cout << i << " ";
        // cout << endl;
        // for (auto i : nums2) cout << i << " ";
        // cout << endl;
        // for (auto i : same_element_after_pos) cout << i << " ";
        // cout << endl;
        return same_element_after_pos;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> nums1_same_element_after_pos = find_same_element_of_range(nums1, nums2);
        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        vector<int> nums2_same_element_before_pos = find_same_element_of_range(nums1, nums2);
        reverse(nums2_same_element_before_pos.begin(), nums2_same_element_before_pos.end());
        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        long long ans = 0;
        for (int i = 0; i < n; i++){
            ans += (long long)nums1_same_element_after_pos[i] * nums2_same_element_before_pos[i];
        }
        return ans;
    }
};

int main(){
    vector<int> nums1 = {2,0,1,3};
    vector<int> nums2 = {0,1,2,3};
    // vector<int> nums1 = {4,0,1,3,2};
    // vector<int> nums2 = {4,1,0,2,3};
    // vector<int> nums1 = {13,14,10,2,12,3,9,11,15,8,4,7,0,6,5,1};
    // vector<int> nums2 = {8,7,9,5,6,14,15,10,2,11,4,13,3,12,1,0};
    Solution S;
    cout << S.goodTriplets(nums1, nums2) << endl;
    return 0;
    
    
    
    
}