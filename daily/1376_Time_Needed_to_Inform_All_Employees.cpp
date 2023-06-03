#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ans = 0;
    vector<vector<int>> edge;
    vector<int> informTime;
    
    void dfs(int i, int minutes){
        if (edge[i].empty()){
            ans = max(ans, minutes);
        }
        else{
            for (auto employee : edge[i]) dfs(employee, minutes + informTime[i]);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& _informTime) {
        informTime = _informTime;
        edge = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) if (i != headID) edge[manager[i]].push_back(i);
        dfs(headID, 0);
        return ans;
    }
};

int main(){
    // int n = 1;
    // int headID = 0;
    // vector<int> manager = {-1};
    // vector<int> informTime = {0};
    int n = 6;
    int headID = 2;
    vector<int> manager = {2,2,-1,2,2,2};
    vector<int> informTime = {0,0,1,0,0,0};
    Solution S;
    cout << S.numOfMinutes(n, headID, manager, informTime) << endl;
    return 0;
}