#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool almost_equal(int i, int j){
        if (i == j) return true;
        int s1[8] = {0};
        int s2[8] = {0};
        int cnt = 0;
        while(i || j){
            s1[cnt] = i % 10;
            s2[cnt] = j % 10;
            cnt++;
            i /= 10;
            j /= 10;
        }
        int diff[2];
        cnt = 0;
        for (int i = 0; i < 8; i++){
            if (s1[i] != s2[i]){
                if (cnt == 2) return false;
                diff[cnt++] = i;
            }
        }
        if (cnt == 0) return true;
        if (cnt == 1) return false;
        int a = diff[0];
        int b = diff[1];
        if (cnt == 2) return (s1[diff[0]] == s2[diff[1]]) && (s1[diff[1]] == s2[diff[0]]);
        return false;
    }
    int countPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> m;
        vector<int> v;
        for (int i : nums){
            if (m[i] == 0) v.push_back(i);
            m[i]++;
        }
        for (auto i : m) ans += i.second * (i.second - 1) / 2;
        int n = v.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (almost_equal(v[i], v[j])){
                    ans += m[v[i]] * m[v[j]];
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     bool almost_equal(int i, int j){
//         if (i == j) return true;
//         int diff1 = -1;
//         int diff2 = -1;
//         bool used = false;
//         while(i || j){
//             int temp1 = i % 10;
//             int temp2 = j % 10;
//             if (temp1 != temp2){
//                 if (used) return false;
//                 else{
//                     if (diff1 == -1){
//                         diff1 = temp1;
//                         diff2 = temp2;
//                     }
//                     else{
//                         if (temp1 == diff2 && temp2 == diff1) used = true;
//                         else return false;
//                     }
//                 }
//             }
//             i /= 10, j /= 10;
//         }
//         return used;
//     }
//     int countPairs(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;
//         vector<vector<bool>> m(n, vector<bool>(n, false));
//         for (int i = 0; i < n; i++){
//             for (int j = i + 1; j < n; j++){
//                 // cout << nums[i] << ", " << nums[j] << " : ";
//                 if (almost_equal(nums[i], nums[j])){
//                     // cout << "true" << endl;
//                     ans++;
//                 }
//                 else{
//                     // cout << "false" << endl;
//                 }
//             }
//         }
//         return ans;
//     }
// };

int main(){
    vector<int> nums = {3,12,30,17,21};
    // vector<int> nums = {1,1,1,1,1};
    // vector<int> nums = {123,231};
    Solution S;
    cout << S.countPairs(nums) << endl;
    return 0;
}