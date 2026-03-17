#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ending(m, vector<int>(n, -1));
        for (int j = 0; j < n; j++){
            int t = m - 1;
            for (int i = m - 1; i >= 0; i--){
                if (matrix[i][j] == 0) t = i - 1;
                else{
                    ending[i][j] = t;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++){
            vector<int>& curr = ending[i];
            sort(curr.begin(), curr.end(), greater<int>());
            int temp = m - 1;
            for (int j = 0; j < n; j++){
                if (curr[j] == -1) break;
                temp = min(temp, curr[j]);
                ans = max(ans, (j + 1) * (temp - i + 1));
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {{0,0,1},{1,1,1},{1,0,1}};
    // vector<vector<int>> matrix = {{1,0,1,0,1}};
    // vector<vector<int>> matrix = {{1,1,0},{1,0,1}};
    Solution S;
    cout << S.largestSubmatrix(matrix) << endl;
    return 0;
}