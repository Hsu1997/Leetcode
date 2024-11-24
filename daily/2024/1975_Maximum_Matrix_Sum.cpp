#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int min_abs = INT_MAX;
        int count_negative = 0;
        for (auto i : matrix){
            for (auto j : i){
                if (j <= 0) count_negative++;
                min_abs = min(min_abs, abs(j));
                ans += abs(j);
            }
        }
        if (count_negative % 2) ans -= 2 * min_abs;
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,-1},{-1,1}};
    // vector<vector<int>> matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};
    // vector<vector<int>> matrix = {{-1,0,-1},{-2,1,3},{3,2,2}};
    // vector<vector<int>> matrix = {{2,9,3},{5,4,-4},{1,7,1}};
    Solution S;
    cout << S.maxMatrixSum(matrix) << endl;
    return 0;
}