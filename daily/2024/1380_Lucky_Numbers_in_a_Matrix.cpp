#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        for (int i = 0; i < m; i++){
            int min = 0;
            for (int j = 1; j < n; j++) if (matrix[i][j] < matrix[i][min]) min = j;
            int lucky = matrix[i][min];
            for (int k = 0; k < m; k++) if (matrix[k][min] > lucky) lucky = matrix[k][min];
            if (lucky == matrix[i][min]) ans.push_back(lucky);
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    // vector<vector<int>> matrix = {{1,10,4,2},{9,3,8,7},{15,16,17,12}};
    // vector<vector<int>> matrix = {{7,8},{1,2}};
    Solution S;
    vector<int> ans = S.luckyNumbers(matrix);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}