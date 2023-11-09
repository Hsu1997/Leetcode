#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};
        for (int i = 1; i <= rowIndex; i++){
            ans.push_back(1);
            for (int j = ans.size()-2; j > 0; j--) ans[j] += ans[j-1];
        }
        return ans;
    }
};

int main(){
    int rowIndex = 3;
    Solution S;
    vector<int> ans = S.getRow(rowIndex);
    for (auto i : ans) cout << i << " ";
    cout << endl;
}