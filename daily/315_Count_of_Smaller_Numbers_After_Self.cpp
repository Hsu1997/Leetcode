#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(int left, int mid, int right, vector<pair<int,int>>& arr, vector<int>& ans){
        int i = left;
        int j = mid + 1;
        int k = 0;
        vector<pair<int,int>> temp(right - left + 1);
        while(i <= mid && j <= right){
            if (arr[i].first <= arr[j].first){
                temp[k++] = arr[j++];
            }
            else{
                ans[arr[i].second] += right - j + 1;
                temp[k++] = arr[i++];
            }
        }
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        while(j <= right){
            temp[k++] = arr[j++];
        }

        for (int i = left; i <= right; i++){
            arr[i] = temp[i - left];
        }
    }

    void mergesort(int left, int right, vector<pair<int,int>>& arr, vector<int>& ans){
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergesort(left, mid, arr, ans);
        mergesort(mid+1, right, arr, ans);
        merge(left, mid, right, arr, ans);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }
        mergesort(0, n-1, arr, ans);
        return ans;
    }
};

int main(){
    // vector<int> nums = {5,2,6,1};
    vector<int> nums = {-1,-1};
    Solution S;
    vector<int> ans = S.countSmaller(nums);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}