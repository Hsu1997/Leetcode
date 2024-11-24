#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> map(m, vector<int>(n, 0));
        for (auto& g : guards){
            int x = g[0];
            int y = g[1];
            map[x][y] = 1;
        }
        for (auto& w : walls){
            int x = w[0];
            int y = w[1];
            map[x][y] = 2;
        }
        for (int i = 0; i < m; i++){
            int curr = 0;
            for (int j = 0; j < n; j++){
                if (map[i][j] == 0) map[i][j] = curr;
                else if (map[i][j] == 1) curr = -1;
                else if (map[i][j] == 2) curr = 0;
                else continue;
            }
            curr = 0;
            for (int j = n-1; j >= 0; j--){
                if (map[i][j] == 0) map[i][j] = curr;
                else if (map[i][j] == 1) curr = -1;
                else if (map[i][j] == 2) curr = 0;
                else continue;
            }
        }
        for (int j = 0; j < n; j++){
            int curr = 0;
            for (int i = 0; i < m; i++){
                if (map[i][j] == 0) map[i][j] = curr;
                else if (map[i][j] == 1) curr = -1;
                else if (map[i][j] == 2) curr = 0;
                else continue;
            }
            curr = 0;
            for (int i = m-1; i >= 0; i--){
                if (map[i][j] == 0) map[i][j] = curr;
                else if (map[i][j] == 1) curr = -1;
                else if (map[i][j] == 2) curr = 0;
                else continue;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (map[i][j] == 0) ans++;
                // cout << map[i][j] << " ";
            }
            // cout << endl;
        }
        return ans;
    }
};

int main(){
    int m = 4;
    int n = 6;
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};
    // int m = 3;
    // int n = 3;
    // vector<vector<int>> guards = {{1,1}};
    // vector<vector<int>> walls = {{0,1},{1,0},{2,1},{1,2}};
    Solution S;
    cout << S.countUnguarded(m, n, guards, walls) << endl;
    return 0;
}