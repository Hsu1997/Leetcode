#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();
        vector<vector<pair<int,int>>> Q(n);
        vector<int> ans(q, -1);
        for (int i = 0; i < q; i++){
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);
            if (a == b || heights[a] < heights[b]) ans[i] = b;
            else Q[b].push_back({heights[a], i});
        }
        vector<pair<int,int>> monotonic;
        for (int i = n-1; i >= 0; i--){
            // int monotonic_size = monotonic.size();
            for (auto& [val, idx] : Q[i]){
                if (monotonic.empty() || monotonic[0].first <= val) ans[idx] = -1;
                else ans[idx] = monotonic[search(monotonic, val)].second;
            }
            while(!monotonic.empty() && monotonic.back().first <= heights[i]) monotonic.pop_back();
            monotonic.push_back({heights[i], i});
        }
        return ans;
    }
private:
    int search(vector<pair<int,int>>& monotonic, int val){
        int left = 0;
        int right = monotonic.size() - 1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (val < monotonic[mid].first){
                ans = max(ans, mid);
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};

int main(){
    vector<int> heights = {6,4,8,5,2,7};
    vector<vector<int>> queries = {{0,1},{0,3},{2,4},{3,4},{2,2}};
    // vector<int> heights = {5,3,8,2,6,1,4,6};
    // vector<vector<int>> queries = {{0,7},{3,5},{5,2},{3,0},{1,6}};
    // vector<int> heights = {1,2,1,2,1,2};
    // vector<vector<int>> queries = {{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{2,0},{2,1},{2,2},{2,3},{2,4},{2,5},{3,0},{3,1},{3,2},{3,3},{3,4},{3,5},{4,0},{4,1},{4,2},{4,3},{4,4},{4,5},{5,0},{5,1},{5,2},{5,3},{5,4},{5,5}};
    Solution S;
    vector<int> ans = S.leftmostBuildingQueries(heights, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}