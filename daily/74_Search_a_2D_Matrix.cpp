#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, l = 0, r = matrix.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if (matrix[mid].back() < target) l = mid + 1;
            else if (matrix[mid].front() > target) r = mid - 1;
            else{
                l = mid;
                break;
            }
        }
        row = l;
        l = 0;
        r = matrix[0].size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] < target) l = mid + 1;
            else if (matrix[row][mid] > target) r = mid - 1;
            else return true;
        }
        return false;
    }
};

int main(){
    // vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> matrix = {{1},{3}};
    int target = 0;
    
    Solution S;
    cout << S.searchMatrix(matrix, target) << endl;
    return 0;
}