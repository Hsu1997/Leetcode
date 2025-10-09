#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> endTime(n, 0);
        for (int i = 0; i < m; i++){
            int curr_task = mana[i];
            endTime[0] += curr_task * skill[0];
            for (int j = 1; j < n; j++){
                endTime[j] = max(endTime[j-1], endTime[j]) + curr_task * skill[j];
            }
            for (int j = n - 2; j >= 0; j--){
                endTime[j] = endTime[j+1] - skill[j+1] * curr_task;
            }
        }
        return endTime.back();
    }
};

int main(){
    vector<int> skill = {1,5,2,4};
    vector<int> mana = {5,1,4,2};
    // vector<int> skill = {1,1,1};
    // vector<int> mana = {1,1,1};
    // vector<int> skill = {1,2,3,4};
    // vector<int> mana = {1,2};
    Solution S;
    cout << S.minTime(skill, mana) << endl;
    return 0;
}