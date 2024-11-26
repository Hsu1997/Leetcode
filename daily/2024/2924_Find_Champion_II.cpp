#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto& i : edges) indegree[i[1]]++;
        int ans = -1;
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0){
                if (ans == -1) ans = i;
                else return -1;
            }
        }
        return ans;
    }
};

int main(){
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2}};
    // int n = 4;
    // vector<vector<int>> edges = {{0,2},{1,3},{1,2}};
    Solution S;
    cout << S.findChampion(n, edges) << endl;
    return 0;
}