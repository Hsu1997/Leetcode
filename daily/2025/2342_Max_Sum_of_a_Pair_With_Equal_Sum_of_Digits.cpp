#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int transfer_to_sum_of_digit(int num){
        int ans = 0;
        while(num){
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
        for (int num : nums){
            int key = transfer_to_sum_of_digit(num);
            // cout << key << " : " << num << endl;
            m[key].push(num);
            if (m[key].size() > 2) m[key].pop();
        }
        int ans = -1;
        for (auto& i : m){
            if (i.second.size() == 2){
                int temp = i.second.top();
                // cout << i.first << " : " << temp << " + ";
                i.second.pop();
                temp += i.second.top();
                // cout << i.second.top() << " = " << temp << endl;
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {18,43,36,13,7};
    // vector<int> nums = {10,12,19,14};
    // vector<int> nums = {229,398,269,317,420,464,491,218,439,153,482,169,411,93,147,50,347,210,251,366,401};
    // 13 : 229
    // 20 : 398
    // 17 : 269
    // 11 : 317, 218
    // 6 : 420, 411
    // 14 : 464, 491, 482, 347
    // 16 : 439, 169
    // 9 : 153
    // 12 : 93, 147
    // 5 : 50, 401
    // 3 : 210
    // 8 : 251
    // 15 : 366
    Solution S;
    cout << S.maximumSum(nums) << endl;
    return 0;
}