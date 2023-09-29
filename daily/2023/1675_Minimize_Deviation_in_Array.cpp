#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int min_num = INT_MAX;
        int diff = INT_MAX;
        priority_queue<int> pq;
        for (auto i : nums){
            if (i % 2 == 1) i *= 2;
            min_num = min(min_num, i);
            pq.push(i);
        }
        while(true){
            int temp = pq.top();
            pq.pop();
            diff = min(diff, temp - min_num);
            if (temp % 2) break;
            temp /= 2;
            min_num = min(min_num, temp);
            pq.push(temp);
        }
        return diff;
    }
};

int main(){
    // vector<int> nums = {1,2,3,4};
    // vector<int> nums = {4,1,5,20,3};
    vector<int> nums = {2,10,8};
    Solution S;
    cout << S.minimumDeviation(nums) << endl;
    return 0;
}