// https://hackmd.io/@wiwiho/cp-note/%2F%40wiwiho%2FCPN-binary-indexed-tree
// BIT usually index [1,n], not contain [0]. If needed, just add each index by 1 to solve it.
#include <iostream>
#include <vector>

using namespace std;

class BIT {
public:
    int n;
    vector<int> tree;
    BIT(vector<int>& nums){
        n = nums.size();
        tree = vector<int>(n+1, 0);
        // BIT usually index [1,n], not contain [0]. If needed, just add each index in update and query function by 1 to solve it.
        for (int i = 0; i < n; i++) updateBIT(i, nums[i]);
    }
    void updateBIT(int index, int value){
        index++;
        while(index <= n){
            tree[index] += value;
            // index add lowbit(index) to carry, move to its right node and parents' right node until whole tree
            index += index & -index;
        }
    }
    int query(int index){
        index++;
        int ans = 0;
        while(index > 0){
            ans += tree[index];
            // each node contain [index - lowbit(index) + 1, index], total lowbit(i) nodes. So we keep going up to add all range
            index -= index & -index;
        }
        return ans;
    }
    int query_range(int left, int right){
        return query(right) - query(left - 1);
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    BIT bit(nums);
    cout << "Range query [1, 3]: " << bit.query_range(1, 3) << endl;
    bit.updateBIT(2, 1);
    cout << "after update =>" << endl << "Range query [1, 3]: " << bit.query_range(1, 3) << endl;
    return 0;
}