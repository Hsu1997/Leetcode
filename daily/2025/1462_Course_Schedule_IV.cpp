#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        for (auto& edge : prerequisites) reachable[edge[0]][edge[1]] = true;
        for (int k = 0; k < numCourses; k++){
            for (int i = 0; i < numCourses; i++){
                for (int j = 0; j < numCourses; j++){
                    if (reachable[i][k] && reachable[k][j]) reachable[i][j] = true;
                }
            }
        }
        int q = queries.size();
        vector<bool> ans(q);
        for (int i = 0; i < q; i++) ans[i] = reachable[queries[i][0]][queries[i][1]];
        return ans;
    }
};

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    vector<vector<int>> queries = {{0,1},{1,0}};
    // int numCourses = 2;
    // vector<vector<int>> prerequisites = {};
    // vector<vector<int>> queries = {{1,0},{0,1}};
    // int numCourses = 3;
    // vector<vector<int>> prerequisites = {{1,2},{1,0},{2,0}};
    // vector<vector<int>> queries = {{1,0},{1,2}};
    Solution S;
    vector<bool> ans = S.checkIfPrerequisite(numCourses, prerequisites, queries);
    for (bool i : ans) cout << i << " ";
    cout << endl;
    return 0;
}