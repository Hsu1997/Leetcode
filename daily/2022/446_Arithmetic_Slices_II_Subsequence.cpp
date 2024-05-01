#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int mul(int n){
        if (n < 3) return 0;
        int ans = 0;
        long temp = n * (n-1) / 2;
        for (int i = 3; i <= n; i++){
            temp = temp * (n-i+1) / i;
            ans += temp;
        }
        return ans;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> m;
        for (auto i : nums) m[i]++;
        for (auto i : m){
            // cout << i.first << " : " << i.second << endl;
            ans += mul(i.second);
        }

        vector<unordered_map<long,int>> v(nums.size());
        for (int i = 1; i < nums.size(); i++){
            // cout << nums[i] << " => " << endl;
            for (int j = 0; j < i; j++){
                long d = (long)nums[i] - (long)nums[j];
                // cout << nums[j] << " : d = " << d << " ";
                if (d != 0){
                    if (v[j][d]){
                        // cout << "find, + " << v[j][d] << endl;  
                        v[i][d] += v[j][d] + 1;
                        ans += v[j][d];
                    }
                    else{
                        // cout << "insert" << endl;
                        v[i][d]++;
                    }
                }
            }
        }
        return (int)ans;
    }
};

// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         long ans = 0;
//         vector<unordered_map<long,int>> v(nums.size());
//         for (int i = 1; i < nums.size(); i++){
//             for (int j = 0; j < i; j++){
//                 long d = (long)nums[i] - (long)nums[j];
//                 if (v[j][d]){
//                     // cout << "find, + " << v[j][d] << endl;  
//                     v[i][d] += v[j][d] + 1;
//                     ans += v[j][d];
//                 }
//                 else{
//                     // cout << "insert" << endl;
//                     v[i][d]++;
//                 }
//             }
//         }
//         return (int)ans;
//     }
// };

int main(){
    // vector<int> nums = {2,4,6,8,10};
    // vector<int> nums = {7,7,7,7,7};
    // vector<int> nums = {2,4,4,4,4,6};
    vector<int> nums = {79,20,64,28,67,81,60,58,97,85,92,96,82,89,46,50,15,2,36,44,54,2,90,37,7,79,26,40,34,67,64,28,60,89,46,31,9,95,43,19,47,64,48,95,80,31,47,19,72,99,28,46,13,9,64,4,68,74,50,28,69,94,93,3,80,78,23,80,43,49,77,18,68,28,13,61,34,44,80,70,55,85,0,37,93,40,47,47,45,23,26,74,45,67,34,20,33,71,48,96};
    Solution S;
    cout << S.numberOfArithmeticSlices(nums) << endl;
    return 0;
}