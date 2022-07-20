#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        for (int j = 0; j < n; j++){
            for (int i = 1; i < m; i++){
                matrix[i][j] += matrix[i-1][j];
            }
        }

        // for (auto i : matrix){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        unordered_map<int, int> count;
        for (int i = 0; i < m; i++){
            for (int k = -1; k < i; k++){
                int temp = 0;
                count.clear();
                count[0]++;
                for (int j = 0; j < n; j++){
                    temp += matrix[i][j] - ((k == -1)? 0 : matrix[k][j]);
                    ans += (count.find(temp - target) != count.end())? count[temp - target] : 0;
                    count[temp]++;
                    // cout << i << ", " << j << ", " << k << " : " << temp << " -- " << ans << endl;
                }
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {{0,1,0},{1,1,1},{0,1,0}};
    int target = 1;
    // vector<vector<int>> matrix = {{1,-1},{-1,1}};
    // int target = 0;
    Solution S;
    cout << S.numSubmatrixSumTarget(matrix, target) << endl;
    return 0;
}