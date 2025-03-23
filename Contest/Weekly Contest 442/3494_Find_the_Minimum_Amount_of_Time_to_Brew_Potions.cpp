#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
    // start=0 : 5, 30-1*1, 40-6*1, 60-8*1 max=52
    // start=52: 53,58-1*4, 60-6*4, 64-8*4 max=54
    // start=54: 58,78-1*2, 86-6*2, 102-8*2max=86
    int n = skill.size();
    int m = mana.size();
    vector<int> acc_skill(n, 0);
    acc_skill[0] = skill[0];
    for (int i = 1; i < n; i++) acc_skill[i] = acc_skill[i-1] + skill[i];
    for (int i = n-1; i > 0; i--) acc_skill[i] = acc_skill[i-1];
    acc_skill[0] = 0;
    mana.push_back(1);
    long long time = 0;
    long long next_round_start = 0;
    for (int pos = 0; pos < m; pos++){
        time = next_round_start;
        long long curr_pos = mana[pos];
        long long next_pos = mana[pos+1];
        for (int s = 0; s < n; s++){
            time += curr_pos * skill[s];
            // cout << "curr = " << time << ", next start = " << time - next_pos * acc_skill[s] << endl;
            next_round_start = max(next_round_start, time - next_pos * acc_skill[s]);
        }
    }
    return time;
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