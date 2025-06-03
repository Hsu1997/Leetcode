#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        int ans = 0;
        vector<bool> visited(n, false);
        vector<bool> found(n, false);
        vector<bool> hasKey(n, false);
        queue<int> que;
        for (int box : initialBoxes){
            found[box] = true;
            if (found[box] && status[box]){
                que.push(box);
                visited[box] = true;
            }
        }
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            ans += candies[curr];
            candies[curr] = 0;
            for (int box : containedBoxes[curr]){
                found[box] = 1;
                if ((status[box] == 1 || hasKey[box]) && !visited[box]){
                    visited[box] = true;
                    que.push(box);
                }
            }
            for (int key : keys[curr]){
                hasKey[key] = 1;
                if (found[key] && status[key] == 0 && !visited[key]){
                    visited[key] = true;
                    que.push(key);
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> status = {1,0,1,0};
    vector<int>  candies = {7,5,4,100};
    vector<vector<int>> keys = {{},{},{1},{}};
    vector<vector<int>>containedBoxes = {{1,2},{3},{},{}};
    vector<int> initialBoxes = {0};
    // vector<int> status = {1,0,0,0,0,0};
    // vector<int>  candies = {1,1,1,1,1,1};
    // vector<vector<int>> keys = {{1,2,3,4,5},{},{},{},{},{}};
    // vector<vector<int>>containedBoxes = {{1,2,3,4,5},{},{},{},{},{}};
    // vector<int> initialBoxes = {0};
    Solution S;
    cout << S.maxCandies(status, candies, keys, containedBoxes, initialBoxes) << endl;
    return 0;
}