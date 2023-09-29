#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        unordered_map<int,unordered_set<int>> m;
        for (auto road : roads){
            m[road[0]].insert(road[1]);
            m[road[1]].insert(road[0]);
        }
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int temp = m[i].size() + m[j].size() - m[i].count(j);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3}};
    Solution S;
    cout << S.maximalNetworkRank(n, roads) << endl;
    return 0;
}