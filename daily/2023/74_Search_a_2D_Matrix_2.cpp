#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = n-1;
        while(i < j){
            int mid = i + (j - i) / 2;
            if (matrix[mid].back() < target) i = mid + 1;
            else if (matrix[mid].front() > target) j = mid - 1;
            else j = i = mid;
        }
        vector<int> &row = matrix[i];
        i = 0;
        j = m - 1;
        while(i < j){
            int mid = i + (j - i) / 2;
            if (row[mid] == target) return true;
            else if (row[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    Solution S;
    cout << S.searchMatrix(matrix, target) << endl;
    return 0;
}