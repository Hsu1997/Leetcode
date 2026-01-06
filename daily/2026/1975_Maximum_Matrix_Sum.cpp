#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int cnt = 0;
        int minNum = INT_MAX;
        for (vector<int>& row : matrix){
            for (int i : row){
                if (i <= 0) cnt++;
                sum += abs(i);
                minNum = min(minNum, abs(i));
            }
        }
        if (cnt % 2 == 1) sum -= 2 * minNum;
        return sum;
    }
};

int main(){
    // vector<vector<int>> matrix = {{1,-1},{-1,1}};
    // vector<vector<int>> matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};
    // vector<vector<int>> matrix = {{-1,0,-1},{-2,1,3},{3,2,2}};
    vector<vector<int>> matrix = {{2,9,3},{5,4,-4},{1,7,1}};
    Solution S;
    cout << S.maxMatrixSum(matrix) << endl;
    return 0;
}