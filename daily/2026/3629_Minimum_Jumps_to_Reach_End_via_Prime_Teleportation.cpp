#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int mx = 1000001;
vector<int> factors[mx];
bool init = [](){
    for (int i = 2; i < mx; i++){
        if (factors[i].empty()){
            for (int j = i; j < mx; j += i){
                factors[j].push_back(i);
            }
        }
    }
    return true;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> primePos;
        for (int i = 0; i < n; i++){
            if (factors[nums[i]].size() == 1 && nums[i] == factors[nums[i]][0]) primePos[nums[i]].push_back(i);
        }
        vector<bool> seen(n, false);
        seen[n-1] = true;
        vector<int> candidate = {n-1};
        int ans = 0;
        while(true){
            vector<int> temp;
            for (int c : candidate){
                if (c == 0) return ans;
                if (c > 0 && !seen[c-1]){
                    seen[c-1] = true;
                    temp.push_back(c-1);
                }
                if (c < n-1 && !seen[c+1]){
                    seen[c+1] = true;
                    temp.push_back(c+1);
                }
                for (int f : factors[nums[c]]){
                    if (primePos.find(f) != primePos.end()){
                        for (int p : primePos[f]){
                            if (!seen[p]){
                                seen[p] = true;
                                temp.push_back(p);
                            }
                        }
                        primePos[f].clear();
                    }
                }
            }
            candidate = std::move(temp);
            ans++;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1,2,4,6};
    // vector<int> nums = {2,3,4,7,9};
    // vector<int> nums = {4,6,5,8};
    Solution S;
    cout << S.minJumps(nums) << endl;
    return 0;
}