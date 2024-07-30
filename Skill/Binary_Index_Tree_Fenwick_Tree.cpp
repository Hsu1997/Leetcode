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


/*
為了實現區間更新和區間查詢，我們需要擴展基本的 BIT 結構，使用兩個 BIT 結構來實現這個功能。這種擴展通常被稱為雙 BIT。

基本概念

雙 BIT 的核心思想是通過兩個 BIT 樹來維護區間更新操作：

	1.	BIT1：用來維護單點的更新值。
	2.	BIT2：用來維護累積的更新增量。

如何實現區間更新和查詢

假設我們有一個數組 arr，其初始值都為 0，我們想要實現兩種操作：

	1.	對區間 [l, r] 進行加值 val 的更新操作。
	2.	查詢某個位置 i 的前綴和。

步驟

更新操作

我們需要更新區間 [l, r] 的每一個元素，使得它們都增加 val。這可以分解為兩個單點更新操作：

	1.	將 val 加到 BIT1[l]，並將 -val * (l - 1) 加到 BIT2[l]。
	2.	將 -val 加到 BIT1[r + 1]，並將 val * r 加到 BIT2[r + 1]。

這樣做的效果是，在區間 [l, r] 內，每個元素都增加 val。

查詢操作

對於查詢位置 i 的前綴和，我們需要計算兩部分的和：

	1.	BIT1 的前綴和，乘以 i。
	2.	BIT2 的前綴和。

這樣，我們可以得到區間 [1, i] 的總和。
*/