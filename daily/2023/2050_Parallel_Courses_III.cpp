#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> start_time(n, 0);
        vector<int> indegree(n, 0);
        vector<vector<int>> edges(n);
        for (auto i : relations){
            edges[i[0]-1].push_back(i[1]-1);
            indegree[i[1]-1]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0){
                que.push(i);
                start_time[i] = 0;
            }
        }
        while(!que.empty()){
            int temp = que.front();
            int temp_time = start_time[temp] + time[temp];
            que.pop();
            for (int neighbor : edges[temp]){
                start_time[neighbor] = max(start_time[neighbor], temp_time);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) que.push(neighbor);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, start_time[i] + time[i]);
        return ans;
    }
};

int main(){
    int n = 3;
    vector<vector<int>> relations = {{1,3},{2,3}};
    vector<int> time = {3,2,5};
    // int n = 5;
    // vector<vector<int>> relations = {{1,5},{2,5},{3,5},{3,4},{4,5}};
    // vector<int> time = {1,2,3,4,5};
    Solution S;
    cout << S.minimumTime(n, relations, time) << endl;
    return 0;
}