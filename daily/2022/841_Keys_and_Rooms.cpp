#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> que;
        visited[0] = true;
        que.push(0);
        while(!que.empty()){
            int temp = que.front();
            que.pop();
            for (auto i : rooms[temp]){
                if (!visited[i]){
                    visited[i] = true;
                    que.push(i);
                }
            }
        }
        // for (auto i : visited) cout << i << " ";
        // cout << endl;
        for (auto i : visited) if (!i) return false;
        return true;
    }
};

int main(){
    // vector<vector<int>> rooms = {{1},{2},{3},{}};
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    Solution S;
    cout << S.canVisitAllRooms(rooms) << endl;
    return 0;
}