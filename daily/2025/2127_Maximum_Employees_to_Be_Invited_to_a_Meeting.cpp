#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverse_graph;
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        int longest_cycle = 0;
        int two_cycle = 0;
        reverse_graph = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) reverse_graph[favorite[i]].push_back(i);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                int distance = 0;
                unordered_map<int,int> curr_round_dist;
                int curr = i;
                while(true){
                    if (visited[curr]) break;
                    visited[curr] = true;
                    curr_round_dist[curr] = distance++;
                    int next = favorite[curr];
                    if (curr_round_dist.find(next) != curr_round_dist.end()){
                        int cycle_length = distance - curr_round_dist[next];
                        if (cycle_length == 2){
                            two_cycle += bfs(reverse_graph, curr, next);
                        }
                        else{
                            longest_cycle = max(longest_cycle, cycle_length);
                        }
                        break;
                    }
                    curr = next;
                }
            }
        }
        return max(longest_cycle, two_cycle);
    }
    int bfs(vector<vector<int>>& reverse_graph, int n1, int n2){
        return bfs_single_side(reverse_graph, n1, n2) + bfs_single_side(reverse_graph, n2, n1);
    }
    int bfs_single_side(vector<vector<int>>& reverse_graph, int n, int restrict){
        queue<int> que;
        que.push(n);
        int ans = 0;
        while(!que.empty()){
            ans++;
            int k = que.size();
            while(k--){
                int curr = que.front();
                que.pop();
                for (int neighbor : reverse_graph[curr]){
                    if (neighbor != restrict) que.push(neighbor);
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> favorite = {2,2,1,2};
    // vector<int> favorite = {1,2,0};
    // vector<int> favorite = {3,0,1,4,1};
    Solution S;
    cout << S.maximumInvitations(favorite) << endl;
    return 0;
}