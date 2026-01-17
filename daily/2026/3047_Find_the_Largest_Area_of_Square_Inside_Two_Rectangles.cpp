#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int p1x1 = bottomLeft[i][0];
                int p1x2 = topRight[i][0];
                int p1y1 = bottomLeft[i][1];
                int p1y2 = topRight[i][1];
                int p2x1 = bottomLeft[j][0];
                int p2x2 = topRight[j][0];
                int p2y1 = bottomLeft[j][1];
                int p2y2 = topRight[j][1];
                int dx = min(p1x2, p2x2) - max(p1x1, p2x1);
                int dy = min(p1y2, p2y2) - max(p1y1, p2y1);
                ans = max(ans, min(dx, dy));
            }
        }
        return 1LL * ans * ans;
    }
};

int main(){
    vector<vector<int>> bottomLeft = {{1,1},{2,2},{3,1}};
    vector<vector<int>> topRight = {{3,3},{4,4},{6,6}};
    // vector<vector<int>> bottomLeft = {{1,1},{1,3},{1,5}};
    // vector<vector<int>> topRight = {{5,5},{5,7},{5,9}};
    // vector<vector<int>> bottomLeft = {{1,1},{2,2},{1,2}};
    // vector<vector<int>> topRight = {{3,3},{4,4},{3,4}};
    // vector<vector<int>> bottomLeft = {{1,1},{3,3},{3,1}};
    // vector<vector<int>> topRight = {{2,2},{4,4},{4,2}};
    Solution S;
    cout << S.largestSquareArea(bottomLeft, topRight) << endl;
    return 0;
}