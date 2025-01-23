#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> mapping(m * n + 1);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                mapping[mat[i][j]] = {i,j};
            }
        }
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for (int i = 0; i < m * n; i++){
            int r = mapping[arr[i]].first;
            int c = mapping[arr[i]].second;
            row[r]++;
            col[c]++;
            if (row[r] == n || col[c] == m) return i;
        }
        return m * n;
    }
};

int main(){
    vector<int> arr ={1,3,4,2};
    vector<vector<int>> mat = {{1,4},{2,3}};
    // vector<int> arr ={2,8,7,4,1,3,5,6,9};
    // vector<vector<int>> mat = {{3,2,5},{1,4,6},{8,7,9}};
    Solution S;
    cout << S.firstCompleteIndex(arr, mat) << endl;
    return 0;
}