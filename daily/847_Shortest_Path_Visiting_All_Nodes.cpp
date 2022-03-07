// hard, reference to the solution

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if (graph.size() <= 1) return 0;

        int n = graph.size();
        int ending_mask = (1 << n) - 1;
        vector< vector<bool> > seen(n, vector<bool>(ending_mask, 0));
        queue< pair<int, int> > q;
        
        for (int i = 0; i < n; i++){
            q.push(make_pair(i, 1 << i));
            seen[i][1 << i] = true;
        }

        int steps = 0;

        while (!q.empty()){
            queue< pair<int, int> > q_new;
            // cout << "q size = " << q.size() << endl;
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i){
                // cout << "in the queue " << i << endl;
                pair<int, int> current_pair = q.front();
                q.pop();
                int node = current_pair.first;
                int mask = current_pair.second;
                for (int neighbor : graph[node]){
                    // cout << "node " << node << "'s neighbor " << neighbor << endl;
                    int next_mask = (mask | (1 << neighbor));
                    if (next_mask == ending_mask) return steps + 1;
                    if (!seen[neighbor][next_mask]){
                        seen[neighbor][next_mask] = true;
                        q_new.push(make_pair(neighbor, next_mask));
                        // cout << "push " << neighbor << ", " << bitset<4>(next_mask) << endl;
                    }
                }
                // cout << "queue " << i << " done" << endl;
            }
            steps++;
            // cout << endl << "from step " << steps - 1 << " to step " << steps << endl;
            swap(q, q_new);
        }
        return -1;
    }
};

int main(){
    // vector< vector<int> > graph = {{1,2,3}, {0}, {0}, {0}};
    vector< vector<int> > graph = {{1},{0,2,4},{1,3,4},{2},{1,2}};
    Solution S;
    cout << S.shortestPathLength(graph) << endl;
    return 0;
}