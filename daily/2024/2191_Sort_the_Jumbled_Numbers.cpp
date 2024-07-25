#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> v;
        for (int i = 0; i < nums.size(); i++){
            string temp = to_string(nums[i]);
            string trans = "";
            for (int j = 0; j < temp.length(); j++){
                trans += to_string(mapping[temp[j]-'0']);
            }
            v.push_back({stoi(trans), i});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for (auto i : v) ans.push_back(nums[i.second]);
        return ans;
    }
};

// MergeSort => stable sort + nlogn algorithm, but not effiency in small dataset
// class Solution {
// public:
//     int trans(vector<int>& mapping, int n){
//         if (n == 0) return mapping[0];
//         int ans = 0;
//         int place = 1;
//         while(n > 0){
//             ans += mapping[n % 10] * place;
//             place *= 10;
//             n /= 10;
//         }
//         return ans;
//     }

//     bool compare(vector<int>& mapping, int a, int b){
//         int newa = trans(mapping, a);
//         int newb = trans(mapping, b);
//         return newa <= newb;
//     }

//     void merge(vector<int>& mapping, vector<int>& nums, int start, int mid, int end){
//         int n1 = mid - start + 1;
//         int n2 = end - mid;
//         vector<int> t1(n1);
//         for (int i = start; i <= mid; i++) t1[i-start] = nums[i];
//         vector<int> t2(n2);
//         for (int i = mid+1; i <= end; i++) t2[i-mid-1] = nums[i];
//         int i = 0;
//         int j = 0;
//         int k = start;
//         while(i < n1 && j < n2){
//             if (compare(mapping, t1[i], t2[j])) nums[k] = t1[i++];
//             else nums[k] = t2[j++];
//             k++;
//         }
//         while(i < n1) nums[k++] = t1[i++];
//         while(j < n2) nums[k++] = t2[j++];
//         return;
//     }

//     void mergesort(vector<int>& mapping, vector<int>& nums, int start, int end){
//         if (start >= end) return;
//         int mid = start + (end - start) / 2;
//         mergesort(mapping, nums, start, mid);
//         mergesort(mapping, nums, mid+1, end);
//         merge(mapping, nums, start, mid, end);
//         return;
//     }

//     vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
//         mergesort(mapping, nums, 0, nums.size()-1);
//         return nums;
//     }
// };

int main(){
    // vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
    // vector<int> nums = {991,338,38};
    vector<int> mapping = {0,1,2,3,4,5,6,7,8,9};
    vector<int> nums = {789,456,123};
    Solution S;
    vector<int> ans = S.sortJumbled(mapping, nums);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}