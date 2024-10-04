#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int total = 0;
        unordered_map<int,int> m;
        for (int i : skill){
            total += i;
            m[i]++;
        }
        int target = total / (n / 2);
        if (total % target != 0) return -1;
        long long ans = 0;
        for (int i : skill){
            if (m[i] > 0){
                m[i]--;
                if (m.find(target - i) == m.end() || m[target - i] == 0) return -1;
                ans += i * (target - i);
                m[target - i]--;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> skill = {3,2,5,1,3,4};
    // vector<int> skill = {3,4};
    // vector<int> skill = {1,1,2,3};
    Solution S;
    cout << S.dividePlayers(skill) << endl;
    return 0;
}