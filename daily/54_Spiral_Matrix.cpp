#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans = {matrix[0][0]};
        matrix[0][0] = -101;
        int i = 0;
        int j = 0;
        vector<vector<int>> der = {{0,1},{1,0},{0,-1},{-1,0}};
        int d = 0;
        while(ans.size() < m * n){
            if (i+der[d][0] >= n || i+der[d][0] < 0 || j+der[d][1] >= m || j+der[d][1] < 0 || matrix[i+der[d][0]][j+der[d][1]] == -101) d = (d+1)%4;
            i += der[d][0];
            j += der[d][1];
            ans.push_back(matrix[i][j]);
            matrix[i][j] = -101;
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution S;
    vector<int> ans = S.spiralOrder(matrix);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}