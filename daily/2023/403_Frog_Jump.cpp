#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int n;
    unordered_map<int,int> m;

    // Define custom hash for pair<int, int>
    struct pair_hash {
        inline size_t operator()(const pair<int,int> & v) const {
            return v.first*31 + v.second;
        }
    };
    
    unordered_map<pair<int, int>, bool, pair_hash> memo;

    bool dfs(vector<int>& stones, int i, int dist){
        if (i == n-1) return true;
        if (memo.count({i,dist})) return memo[{i,dist}];

        for (int d = -1; d <= 1; d++){
            if (dist+d > 0 && m.count(stones[i]+dist+d) && dfs(stones, m[stones[i]+dist+d], dist+d)) return true;
        }
        memo[{i,dist}] = false;
        return memo[{i,dist}];
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[0] != 0 || stones[1] != 1) return false;
        for (int i = 1; i < n; i++) m[stones[i]] = i;
        return dfs(stones, 1, 1);
    }
};

int main(){
    // vector<int> stones = {0,1,3,5,6,8,12,17};
    vector<int> stones = {0,1,2,3,4,8,9,11};
    Solution S;
    cout << S.canCross(stones) << endl;
    return 0;
}