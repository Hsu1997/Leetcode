#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double,int>>> path(n);
        for (int i = 0; i < edges.size(); i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            double prob = succProb[i];
            path[n1].push_back({prob, n2});
            path[n2].push_back({prob, n1});
        }
        vector<double> arrive(n, 0);
        priority_queue<pair<double,int>,vector<pair<double,int>>, less<pair<double,int>>> pq;
        arrive[start_node] = 1;
        pq.push({1.0, start_node});
        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (node == end_node) return prob;
            for (auto [path_prob, next_node] : path[node]){
                double new_prob = prob * path_prob;
                if (new_prob > arrive[next_node]) pq.push({new_prob, next_node}), arrive[next_node] = new_prob;
            }
        }
        return arrive[end_node];
    }
};

int main(){
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    int start_node = 0;
    int end_node = 2;
    // int n = 3;
    // vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    // vector<double> succProb = {0.5,0.5,0.3};
    // int start_node = 0;
    // int end_node = 2;
    // int n = 3;
    // vector<vector<int>> edges = {{0,1}};
    // vector<double> succProb = {{0,5}};
    // int start_node = 0;
    // int end_node = 2;
    Solution S;
    cout << S.maxProbability(n, edges, succProb, start_node, end_node) << endl;
    return 0;
}