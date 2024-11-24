#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> count;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++){
            // all 0
            string temp;
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0) temp += '.';
                else temp += 'f';
            }
            count[temp]++;
            // all 1
            temp = "";
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0) temp += 'f';
                else temp += '.';
            }
            count[temp]++;
        }
        int ans = 0;
        for (auto i : count) ans = max(ans, i.second);
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {{0,1},{1,1}};
    // vector<vector<int>> matrix = {{0,1},{1,0}};
    // vector<vector<int>> matrix = {{0,0,0},{0,0,1},{1,1,0}};
    Solution S;
    cout << S.maxEqualRowsAfterFlips(matrix) << endl;
    return 0;
}