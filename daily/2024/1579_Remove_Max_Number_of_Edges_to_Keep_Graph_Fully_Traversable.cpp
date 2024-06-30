#include <iostream>
#include <vector>

using namespace std;

class Union_Set {
public:
    vector<int> parents, rank;

    Union_Set(int n){
        parents.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parents[i] = i;
    }

    int find(int x){
        return (x == parents[x])? x : parents[x] = find(parents[x]);
    }

    void combine(int x, int y){
        int xset = find(x);
        int yset = find(y);
        if (rank[xset] < rank[yset]) parents[xset] = yset;
        else parents[yset] = xset;
        if (rank[xset] == rank[yset]) rank[xset]++; 
        return;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](vector<int>& a,vector<int>& b){return a[0] > b[0];});
        
        Union_Set alice(n+1);
        Union_Set bob(n+1);
        int alice_node = 1;
        int bob_node = 1;
        int remove = 0;

        for (auto e : edges){
            if (e[0] == 3){
                if (alice.find(e[1]) != alice.find(e[2]) || bob.find(e[1]) != bob.find(e[2])){
                    if (alice.find(e[1]) != alice.find(e[2])) alice.combine(e[1],e[2]), alice_node++;
                    if (bob.find(e[1]) != bob.find(e[2])) bob.combine(e[1], e[2]), bob_node++;
                }
                else remove++;
            }
            else if (e[0] == 2){
                if (bob.find(e[1]) != bob.find(e[2])) bob.combine(e[1], e[2]), bob_node++;
                else remove++;
            }
            else{
                if (alice.find(e[1]) != alice.find(e[2])) alice.combine(e[1], e[2]), alice_node++;
                else remove++;
            }
        }
        return (alice_node == n && bob_node == n)? remove : -1;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> edges = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    // int n = 4;
    // vector<vector<int>> edges = {{3,1,2},{3,2,3},{1,1,4},{2,1,4}};
    // int n = 4;
    // vector<vector<int>> edges = {{3,2,3},{1,1,2},{2,3,4}};
    Solution S;
    cout << S.maxNumEdgesToRemove(n, edges) << endl;
    return 0;
}