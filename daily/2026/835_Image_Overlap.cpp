#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for (int dx = - n + 1; dx < n; dx++){
            for (int dy = - n + 1; dy < n; dy++){
                int cnt = 0;
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        if (i + dx < 0 || i + dx >= n || j + dy < 0 || j + dy >= n) continue;
                        if (img1[i][j] == 1 && img2[i + dx][j + dy] == 1) cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> img1 = {{1,1,0},{0,1,0},{0,1,0}};
    vector<vector<int>> img2 = {{0,0,0},{0,1,1},{0,0,1}};
    // vector<vector<int>> img1 = {{1}};
    // vector<vector<int>> img2 = {{1}};
    // vector<vector<int>> img1 = {{0}};
    // vector<vector<int>> img2 = {{0}};
    // vector<vector<int>> img1 = {{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    // vector<vector<int>> img2 = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{1,0,0,0,0}};
    Solution S;
    cout << S.largestOverlap(img1, img2) << endl;
    return 0;
}