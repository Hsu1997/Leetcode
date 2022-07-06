#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int ans = 0;
//         unordered_set<int> S;
//         for (auto i : nums) S.insert(i);
//         for (auto i : nums){
//             if (S.find(i-1) == S.end()){
//                 int consecutive = 1;
//                 int temp = i+1;
//                 while(S.find(temp) != S.end()) consecutive++, temp++;
//                 ans = max(ans, consecutive);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,bool> M;
        for (auto i : nums) M[i] = true;
        for (auto i : nums){
            if (M[i-1] == false){
                int consecutive = 1;
                int temp = i+1;
                while(M[temp]) consecutive++, temp++;
                ans = max(ans, consecutive);
            }
        }
        return ans;
    }
};

// two ways runtime are in essence the same.

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    // vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution S;
    cout << S.longestConsecutive(nums) << endl;
    return 0;
}