#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getrec(vector<vector<int>>& P, int x1, int x2, int y1, int y2){
        return P[x2+1][y2+1] - P[x1][y2+1] - P[x2+1][y1] + P[x1][y1];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        vector<vector<int>> P(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++){
            int acc = 0;
            for (int j = 0; j < n; j++){
                acc += mat[i][j];
                P[i+1][j+1] = P[i][j+1] + acc;
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                for (int e = ans + 1; e <= min(m, n); e++){
                    if (i + e - 1< m && j + e - 1< n && getrec(P, i, i + e - 1, j, j + e - 1) <= threshold) ans = e;
                    else break;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> mat = {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}};
    int threshold = 4;
    // vector<vector<int>> mat = {{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2}};
    // int threshold = 1;
    Solution S;
    cout << S.maxSideLength(mat, threshold) << endl;
    return 0;
}