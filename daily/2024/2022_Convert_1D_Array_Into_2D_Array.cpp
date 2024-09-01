#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < original.size(); i++) ans[i / n][i % n] = original[i];
        return ans;
    }
};

int main(){
    vector<int> original = {1,2,3,4};
    int m = 2;
    int n = 2;
    // vector<int> original = {1,2,3};
    // int m = 1;
    // int n = 3;
    // vector<int> original = {1,2};
    // int m = 1;
    // int n = 1;
    Solution S;
    vector<vector<int>> ans = S.construct2DArray(original, m, n);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}