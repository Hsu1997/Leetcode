#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Union {
public:
    vector<int> u;
    Union(int n){
        u.resize(n);
        for (int i = 0; i < n; i++) u[i] = i;
    }
    int find(int i){
        if (u[i] == i) return i;
        else return u[i] = find(u[i]);
    }
    void combine(int a, int b){
        u[find(a)] = find(b);
    }
};

class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        return a[2] < b[2];
    }

    int find_MST_force(int n, vector<vector<int>>& edges, int force){
        int weight = 0;
        int e = 0;
        Union group(n);
        group.combine(edges[force][0], edges[force][1]);
        e++;
        weight += edges[force][2];
        for (int i = 0; i < edges.size(); i++){
            if (i == force) continue;
            else if (e == n-1) break;
            else{
                int a = edges[i][0];
                int b = edges[i][1];
                if (group.find(a) == group.find(b)) continue;
                else{
                    group.combine(a,b);
                    weight += edges[i][2];
                    e++;
                }
            }
        }
        return (e == n-1)? weight : -1;
    }

    int find_MST_weight(int n, vector<vector<int>>& edges, int ignore){
        int weight = 0;
        int e = 0;
        Union group(n);
        for (int i = 0; i < edges.size(); i++){
            if (i == ignore) continue;
            else if (e == n-1) break;
            else{
                int a = edges[i][0];
                int b = edges[i][1];
                if (group.find(a) == group.find(b)) continue;
                else{
                    group.combine(a,b);
                    weight += edges[i][2];
                    e++;
                }
            }
        }
        return (e == n-1)? weight : -1;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<vector<int>> ans(2);
        for (int i = 0; i < e; i++) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), compare);
        // for (auto i : edges){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        int min_mst_weight = find_MST_weight(n, edges, e);
        // cout << "MST weight = " << min_mst_weight << endl;
        for (int i = 0; i < e; i++){
            // cout << "edge " << edges[i][3] << " : ";
            int ignore = find_MST_weight(n, edges, i);
            int force = find_MST_force(n, edges, i);
            // cout << "ignore = " << ignore << ", force = " << force << endl;
            if (ignore == -1 || ignore > min_mst_weight) ans[0].push_back(edges[i][3]);
            else{
                if (force == min_mst_weight) ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};

int main(){
    // int n = 5;
    // vector<vector<int>> edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    // int n = 4;
    // vector<vector<int>> edges = {{0,1,1},{1,2,1},{2,3,1},{0,3,1}};
    int n = 6;
    vector<vector<int>> edges = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
    Solution S;
    vector<vector<int>> ans = S.findCriticalAndPseudoCriticalEdges(n, edges);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}