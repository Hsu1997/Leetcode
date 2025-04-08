#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int visited[101] = {0};
        int count = -1;
        for (int i = n-1; i >= 0; i--){
            if (visited[nums[i]] == 1){
                count = i;
                break;
            }
            visited[nums[i]] = 1;
        }
        count++;
        return count / 3 + (count % 3 > 0);
    }
};

int main(){
    vector<int> nums = {1,2,3,4,2,3,3,5,7};
    // vector<int> nums = {4,5,6,4,4};
    // vector<int> nums = {6,7,8,9};
    // vector<int> nums = {46,75,66,51,66,7,100,19,87,46,12,25};
    Solution S;
    cout << S.minimumOperations(nums) << endl;
    return 0;
}