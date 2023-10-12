#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> edge[numCourses];
        vector<int> indegree(numCourses);
        vector<bool> visited(numCourses);
        for (auto i : prerequisites){
            indegree[i[1]]++;
            edge[i[0]].push_back(i[1]);
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++) if (indegree[i] == 0) que.push(i), visited[i] = true;
        while(!que.empty()){
            int temp = que.front();
            que.pop();
            for (auto i : edge[temp]){
                if (visited[i]) return false;
                indegree[i]--;
                if (indegree[i] == 0) que.push(i);
            }
            visited[temp] = true;
        }
        for (int i = 0; i < numCourses; i++) if (!visited[i] && indegree[i]) return false;
        return true;
    }
};

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    // int numCourses = 2;
    // vector<vector<int>> prerequisites = {{1,0},{0,1}};
    Solution S;
    cout << S.canFinish(numCourses, prerequisites) << endl;
    return 0;
}