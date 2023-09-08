#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        vector<int> temp = {1};
        for (int i = 2; i <= numRows; i++){
            for (int j = i-2; j > 0; j--) temp[j] += temp[j-1];
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(){
    int numRows = 8;
    Solution S;
    vector<vector<int>> ans = S.generate(numRows);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}