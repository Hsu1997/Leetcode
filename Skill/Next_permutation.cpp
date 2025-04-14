#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 實作 next_permutation
bool nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;

    // 找到第一個上升點
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;

    // 如果是遞減序列 => 已經是最後一個排列
    if (i < 0) return false; 

    // 從後找比 nums[i] 大的元素（後面是從比nums[i]大的數開始的遞減數列）
    int j = nums.size() - 1;
    while (nums[j] <= nums[i]) j--;
    // 交換後 後面還是遞減數列
    swap(nums[i], nums[j]);

    // 反轉後面那一段 變成遞增數列 => 把最後一個遞增的數字換成大一號的 然後後面是從小到大的排列
    reverse(nums.begin() + i + 1, nums.end());

    return true;
}

// 遞迴列印所有排列
void printAllPermutations(vector<int> nums) {
    // 列印當前排列
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;

    // 如果還有下一個排列，則繼續遞迴
    if (nextPermutation(nums)) {
        printAllPermutations(nums);
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    sort(nums.begin(), nums.end()); // 確保從最小開始
    printAllPermutations(nums);
    return 0;
}