#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long ans = 0;
    int n;
    int seats;
    vector<bool> visited;
    vector<vector<int>> edge;
    
    int dfs(int i){
        int people = 1;
        for (auto next : edge[i]){
            if (!visited[next]){
                // cout << "from " << i << " to " << next << endl;
                visited[next] = true;
                int temp = dfs(next);
                people += temp;
                visited[next] = false;
                // cout << "ans add " << temp / seats + (temp % seats > 0) << endl;
                ans += temp / seats + (temp % seats > 0);
            }
        }
        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int _seats) {
        n = roads.size()+1;
        seats = _seats;
        if (n == 1) return ans;
        visited = vector<bool>(n, false);
        visited[0] = true;
        edge = vector<vector<int>>(n);
        for (auto i : roads){
            edge[i[0]].push_back(i[1]);
            edge[i[1]].push_back(i[0]);
        }
        dfs(0);
        return ans;
    }
};

int main(){
    // vector<vector<int>> roads = {{0,1},{0,2},{0,3}};
    // int seats = 5;
    vector<vector<int>> roads = {{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}};
    int seats = 2;
    Solution S;
    cout << S.minimumFuelCost(roads, seats) << endl;
    return 0;
}