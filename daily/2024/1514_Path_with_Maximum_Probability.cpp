#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct Node{
        int destination;
        double probability;
        Node* next;
        Node(int d, double p, Node* n) : destination(d), probability(p), next(n) {}
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n, 0);
        prob[start_node] = 1.0;
        vector<Node*> e(n);
        for (int i = 0; i < edges.size(); i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            double p = succProb[i];
            e[n1] = new Node(n2, p, e[n1]);
            e[n2] = new Node(n1, p, e[n2]);
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        int round = 0;
        while(!pq.empty() && round < n){
            round++;
            auto [p, node] = pq.top();
            if (node == end_node) return p;
            pq.pop();
            Node* neighbor = e[node];
            while(neighbor){
                if (prob[neighbor->destination] < p * neighbor->probability){
                    prob[neighbor->destination] = p * neighbor->probability;
                    pq.push({prob[neighbor->destination], neighbor->destination});
                }
                neighbor = neighbor->next;
            }
        }
        return prob[end_node];
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
    // vector<double> succProb = {0.5};
    // int start_node = 0;
    // int end_node = 2;
    Solution S;
    cout << S.maxProbability(n, edges, succProb, start_node, end_node) << endl;
    return 0;
}