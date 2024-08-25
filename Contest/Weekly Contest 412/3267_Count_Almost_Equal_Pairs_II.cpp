#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater());
        int ans = 0;
        // for (auto i : nums) cout << i << " ";
        // cout << endl;
        unordered_map<int, int> count;
        unordered_set<int> s;
        for (int index = 0; index < n; index++){
            int c = 1;
            while (index + 1 < n && nums[index + 1] == nums[index]) c++, index++;
            ans += c * (c - 1) / 2;
            ans += count[nums[index]] * c;
            string curr = to_string(nums[index]);
            int k = curr.length();
            for (int i = 0; i < k; i++){
                for (int j = i; j < k; j++){
                    swap(curr[i], curr[j]);
                    for (int a = 0; a < k; a++){
                        for (int b = a; b < k; b++){
                            swap(curr[a], curr[b]);
                            s.insert(stoi(curr));
                            swap(curr[a], curr[b]);
                        }
                    }
                    swap(curr[i], curr[j]);
                }
            }
            for (int temp : s) count[temp] += c;
            s.clear();
        }
        return ans;
    }
};

// class Solution {
// public:
//     bool almost_equal(int i, int j){
//         if (i == j) return true;
//         int s1[8] = {0};
//         int s2[8] = {0};
//         int cnt = 0;
//         while(i || j){
//             s1[cnt] = i % 10;
//             s2[cnt] = j % 10;
//             cnt++;
//             i /= 10;
//             j /= 10;
//         }
//         int diff[4];
//         cnt = 0;
//         for (int i = 0; i < 8; i++){
//             if (s1[i] != s2[i]){
//                 if (cnt == 4) return false;
//                 diff[cnt++] = i;
//             }
//         }
//         if (cnt == 0) return true;
//         if (cnt == 1) return false;
//         int a = diff[0];
//         int b = diff[1];
//         if (cnt == 2) return (s1[diff[0]] == s2[diff[1]]) && (s1[diff[1]] == s2[diff[0]]);
//         int c = diff[2];
//         if (cnt == 3){
//             return (s1[a] == s2[b] && s1[b] == s2[c] && s1[c] == s2[a])|| 
//                    (s1[a] == s2[c] && s1[b] == s2[a] && s1[c] == s2[b]);
//         }
//         int d = diff[3];
//         if (cnt == 4){
//             return (s1[a] == s2[b] && s1[b] == s2[a] && s1[c] == s2[d] && s1[d] == s2[c])||
//                    (s1[a] == s2[c] && s1[c] == s2[a] && s1[b] == s2[d] && s1[d] == s2[b])||
//                    (s1[a] == s2[d] && s1[d] == s2[a] && s1[b] == s2[c] && s1[c] == s2[b]);
//         }
//         return false;
//     }
//     int countPairs(vector<int>& nums) {
//         int ans = 0;
//         unordered_map<int,int> m;
//         vector<int> v;
//         for (int i : nums){
//             if (m[i] == 0) v.push_back(i);
//             m[i]++;
//         }
//         for (auto i : m) ans += i.second * (i.second - 1) / 2;
//         int n = v.size();
//         for (int i = 0; i < n; i++){
//             for (int j = i + 1; j < n; j++){
//                 if (almost_equal(v[i], v[j])){
//                     ans += m[v[i]] * m[v[j]];
//                 }
//             }
//         }
//         return ans;
//     }
// };

int main(){
    // vector<int> nums = {1023,2310,2130,213};
    // vector<int> nums = {1,10,100};
    vector<int> nums = {4837,8223,3487,3822,8223,7032,172,8232,8678,3758,2588,6734,4301,2823,721,172,3647,4031,3746,8232,6041,6878,3282,3282,7809,7023,3118,721,3822,8852,2823,5927,2823,8734,8223,3822,3228,2832,2328,8322,8322,3282,3746,172,4310,3282,8473,3822,4031,2382,3764,4031,7230,2382,5376,3822,8232,2283,3282,3228,8322,172,3282,8232,2283,3746,2238,8232,2328,7780,2823,3476,8232,2382,8223,2283,2283,8223};
    Solution S;
    cout << S.countPairs(nums) << endl;
    return 0;
}