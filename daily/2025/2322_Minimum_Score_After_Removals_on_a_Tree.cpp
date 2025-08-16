#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int t;
    vector<vector<int>> graph;
    vector<int> suffix;
    vector<int> tin;
    vector<int> tout;

    void dfs(int index, int parents, vector<int>& nums){
        tin[index] = t++;
        int curr = nums[index];
        for (int neighbor : graph[index]){
            if (neighbor == parents) continue;
            dfs(neighbor, index, nums);
            curr ^= suffix[neighbor];
        }
        suffix[index] = curr;
        tout[index] = t++;
        return;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        t = 0;
        graph = vector<vector<int>>(n);
        suffix = vector<int>(n);
        tin = vector<int>(n);
        tout = vector<int>(n);
        for (auto& edge : edges){
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(0, -1, nums);
        int ans = INT_MAX;
        for (int i = 1; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (tin[i] < tin[j] && tout[i] > tout[j]){
                    int a = suffix[0] ^ suffix[i];
                    int b = suffix[i] ^ suffix[j];
                    int c = suffix[j];
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
                else if (tin[j] < tin[i] && tout[j] > tout[i]){
                    int a = suffix[0] ^ suffix[j];
                    int b = suffix[j] ^ suffix[i];
                    int c = suffix[i];
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
                else{
                    int a = suffix[0] ^ suffix[i] ^ suffix[j];
                    int b = suffix[i];
                    int c = suffix[j];
                    ans = min(ans, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,5,5,4,11};
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    // vector<int> nums = {5,5,2,4,4,2};
    // vector<vector<int>> edges = {{0,1},{1,2},{5,2},{4,3},{1,3}};
    // vector<int> nums = {9,14,2,1};
    // vector<vector<int>> edges = {{2,3},{3,0},{3,1}};
    Solution S;
    cout << S.minimumScore(nums, edges) << endl;
    return 0;
}