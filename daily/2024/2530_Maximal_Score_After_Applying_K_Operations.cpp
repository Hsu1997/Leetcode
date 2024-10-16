#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i : nums) pq.push(i);
        long long ans = 0;
        for (int i = 0; i < k; i++){
            int temp = pq.top();
            pq.pop();
            pq.push(temp / 3 + (temp % 3 > 0));
            ans += temp;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {10,10,10,10,10};
    int k = 5;
    // vector<int> nums = {1,10,3,3,3};
    // int k = 3;
    Solution S;
    cout << S.maxKelements(nums, k) << endl;
    return 0;
}