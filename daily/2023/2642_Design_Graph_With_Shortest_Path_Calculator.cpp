#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int n;
    vector<vector<pair<int,int>>> e;

    Graph(int _n, vector<vector<int>>& edges) {
        n = _n;
        e.resize(n);
        for (auto i : edges) e[i[0]].push_back({i[2],i[1]});
    }
    
    void addEdge(vector<int> edge) {
        e[edge[0]].push_back({edge[2],edge[1]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool> v(n, false);
        vector<int> dis(n, INT_MAX);
        dis[node1] = 0;
        for (int k = 0; k < n; k++){
            int min_dis = INT_MAX;
            int min_node = -1;
            for (int i = 0; i < n; i++){
                if (dis[i] < min_dis && v[i] == false) min_dis = dis[i], min_node = i;
            }
            if (min_node == -1) return (dis[node2] == INT_MAX)? -1 : dis[node2];
            v[min_node] = true;
            for (auto i : e[min_node]){
                dis[i.second] = min(dis[i.second], dis[min_node]+i.first);
            }
        }
        return (dis[node2] == INT_MAX)? -1 : dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

int main(){
    int n = 4;
    vector<vector<int>> edges = {{0,2,5},{0,1,2},{1,2,1},{3,0,3}};
    Graph* g = new Graph(n, edges);
    cout << g->shortestPath(3, 2) << endl; // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
    cout << g->shortestPath(0, 3) << endl; // return -1. There is no path from 0 to 3.
    g->addEdge({1, 3, 4}); // We add an edge from node 1 to node 3, and we get the second diagram above.
    cout << g->shortestPath(0, 3) << endl; // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.
    return 0;
}