#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count;
        unordered_map<int,int> seq_end;
        for (auto i : nums) count[i]++;

        for (auto i : nums){
            if (!count[i]) continue;

            if (seq_end[i-1]) seq_end[i-1]--,seq_end[i]++;
            else{
                if (count[i+1] == 0 || count[i+2] == 0) return false;
                count[i+1]--, count[i+2]--,seq_end[i+2]++;
            }
            count[i]--;
        }
        return true;
    }
};

int main(){
    // vector<int> nums = {1,2,3,3,4,5};
    // vector<int> nums = {1,2,3,3,4,4,5,5};
    vector<int> nums = {1,2,3,4,4,5};
    
    Solution S;
    cout << S.isPossible(nums) << endl;
    return 0;
}