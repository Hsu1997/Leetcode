#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> dist(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                dist[i][j] = j - i;
            }
        }
        int q = queries.size();
        vector<int> ans(q);
        for (int k = 0; k < q; k++){
            int start = queries[k][0];
            int end = queries[k][1];
            dist[start][end] = 1;
            for (int i = 0; i <= start; i++){
                for (int j = end; j < n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][start] + dist[start][end] + dist[end][j]);
                }
            }
            ans[k] = dist[0][n-1];
            // for (auto i : dist){
            //     for (auto j : i) cout << j << " ";
            //     cout << endl;
            // }
            // cout << endl;
        }
        return ans;
    }
};

int main(){
    int n = 5;
    vector<vector<int>> queries = {{2,4},{0,2},{0,4}};
    // int n = 4;
    // vector<vector<int>> queries = {{0,3},{0,2}};
    Solution S;
    vector<int> ans = S.shortestDistanceAfterQueries(n, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}