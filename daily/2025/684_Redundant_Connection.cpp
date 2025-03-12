#include <iostream>
#include <vector>

using namespace std;

class Union_Find{
public:
    vector<int> parents;
    vector<int> rank;
    Union_Find(int n){
        parents.resize(n);
        for (int i = 0; i < n; i++) parents[i] = i;
        rank = vector<int>(n, 1);
    }
    int find(int i){
        if (parents[i] != i) return parents[i] = find(parents[i]);
        else return i;
    }
    bool combine(int i, int j){
        int s1 = find(i);
        int s2 = find(j);
        if (s1 == s2) return false;
        if (rank[s1] > rank[s2]) parents[s2] = s1;
        else if (rank[s1] < rank[s2]) parents[s1] = s2;
        else{
            parents[s2] = s1;
            rank[s1]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Union_Find u(n+1);
        for (auto& edge : edges){
            if (!u.combine(edge[0], edge[1])) return edge;
        }
        return {};
    }
};

int main(){
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    // vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    Solution S;
    vector<int> ans = S.findRedundantConnection(edges);
    cout << ans[0] << ", " << ans[1] << endl;
    return 0;
}