#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 5){
            sort(nums.begin(), nums.end());
            return nums[n-k];
        }
        vector<int> median_group;
        vector<int> greater_median;
        vector<int> less_median;
        int group_num = ceil(n/5);
        // while (nums.size() % 5 != 0) nums.push_back(numeric_limits<int>::min());
        for (int i = 0; i < group_num; i++){
            auto b = nums.begin()+5*i;
            auto e = (i == group_num-1 && n%5 != 0)? nums.begin()+5*i+(n%5) : b+5;
            sort(b, e);
            median_group.push_back(*(b+(e-b-1)/2));
        }
        int median = (median_group.size() > 1)? findKthLargest(median_group, median_group.size()/2) : median_group.front();
        bool already_find_median = false;
        for (auto i : nums){
            if (i < median) less_median.push_back(i);
            else if (i == median && !already_find_median) already_find_median = true;
            else greater_median.push_back(i);
        }
        if (greater_median.size() >= k) return findKthLargest(greater_median, k);
        else if (greater_median.size() == k-1) return median;
        else return findKthLargest(less_median, k-greater_median.size()-1);
        return -1;
    }
};

int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    Solution S;
    cout << S.findKthLargest(nums, k) << endl;
    return 0;
}