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

int main(){
    // vector<int> nums = {1023,2310,2130,213};
    // vector<int> nums = {1,10,100};
    vector<int> nums = {4837,8223,3487,3822,8223,7032,172,8232,8678,3758,2588,6734,4301,2823,721,172,3647,4031,3746,8232,6041,6878,3282,3282,7809,7023,3118,721,3822,8852,2823,5927,2823,8734,8223,3822,3228,2832,2328,8322,8322,3282,3746,172,4310,3282,8473,3822,4031,2382,3764,4031,7230,2382,5376,3822,8232,2283,3282,3228,8322,172,3282,8232,2283,3746,2238,8232,2328,7780,2823,3476,8232,2382,8223,2283,2283,8223};
    Solution S;
    cout << S.countPairs(nums) << endl;
    return 0;
}