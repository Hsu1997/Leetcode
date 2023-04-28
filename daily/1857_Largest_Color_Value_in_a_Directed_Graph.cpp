#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int n;
    int ans = 0;
    string colors;
    vector<bool> visited;
    vector<bool> circle;
    vector<vector<int>> edge;
    vector<vector<int>> color_map;

    void combine(vector<int>& a, vector<int>& b){
        for (int i = 0; i < 26; i++) a[i] = max(a[i], b[i]);
    }

    int dfs(int i){
        if (circle[i]) return -1;
        if (visited[i]) return color_map[i][colors[i]-'a'];

        visited[i] = true;
        circle[i] = true;
        for (auto neighbor : edge[i]){
            if (dfs(neighbor) == -1) return -1;
            combine(color_map[i], color_map[neighbor]);
        }
        color_map[i][colors[i]-'a']++;
        circle[i] = false;
        return color_map[i][colors[i]-'a'];
    }

    int largestPathValue(string _colors, vector<vector<int>>& edges) {
        n = _colors.length();
        colors = _colors;
        visited = vector<bool>(n, false);
        circle = vector<bool>(n, false);
        edge = vector<vector<int>>(n);
        color_map = vector<vector<int>>(n, vector<int>(26,0));
        for (auto i : edges){
            if (i[0] == i[1]) return -1;
            edge[i[0]].push_back(i[1]);
        }
        for (int i = 0; i < n; i++){
            int temp = dfs(i);
            if (temp == -1) return -1;
            else ans = max(ans, temp);
        }
        return ans;
    }
};

int main(){
    string colors = "abaca";
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{3,4}};
    // string colors = "a";
    // vector<vector<int>> edges = {{0,0}};
    // string colors = "rrrde";
    // vector<vector<int>> edges = {{4,2},{3,4},{0,3},{1,0},{2,1}};
    Solution S;
    cout << S.largestPathValue(colors, edges) << endl;
    return 0;
}