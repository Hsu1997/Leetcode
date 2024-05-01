#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    int n;
    vector<int> segment_tree;

    void build(int L, int R, int v, vector<int>& nums){
        if (L == R){
            segment_tree[v] = nums[L];
            return;
        }
        int mid = L + (R - L) / 2;
        build(L, mid, v*2+1, nums);
        build(mid+1, R, v*2+2, nums);
        segment_tree[v] = segment_tree[v*2+1] + segment_tree[v*2+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segment_tree = vector<int>(nums.size() * 4, 0);
        build(0, n-1, 0, nums);

        // for (auto i : segment_tree) cout << i << " ";
        // cout << endl;
    }
    
    void update(int index, int val) {
        int L = 0;
        int R = n-1;
        int v = 0;
        while(L != R){
            int mid = L + (R-L)/2;
            if (index <= mid) R = mid, v = v*2+1;
            else L = mid+1, v = v*2+2;
        }
        segment_tree[v] = val;
        while(v > 0){
            v = (v-1)/2;
            segment_tree[v] = segment_tree[v*2+1] + segment_tree[v*2+2];
        }

        // for (auto i : segment_tree) cout << i << " ";
        // cout << endl;
    }
    
    int query(int left, int right, int v, int L, int R){
        // (left, right) is the range we are required to query.
        // (L, R) is the range of position v represent.
        if (L == left && R == right) return segment_tree[v];
        int mid = L + (R-L)/2;
        if (right <= mid) return query(left, right, v*2+1, L, mid);
        else if (left > mid) return query(left, right, v*2+2, mid+1, R);
        else return query(left, mid, v*2+1, L, mid) + query(mid+1, right, v*2+2, mid+1, R);
    }

    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(){
    vector<int> nums = {1,3,5};
    NumArray* N = new NumArray(nums);
    cout << N->sumRange(0,2) << endl;
    N->update(1,2);
    cout << N->sumRange(0,2) << endl;
    return 0;
}