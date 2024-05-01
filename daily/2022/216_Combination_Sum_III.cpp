#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int number;
    int target;

    void subproblem(int start, vector<int> &temp, int sum){
        if (temp.size() == number && sum == target){
            ans.push_back(temp);
            return;
        }
        for (int i = start; i < 10; i++){
            if (sum + i > target) return;
            temp.push_back(i);
            subproblem(i+1, temp, sum+i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        number = k;
        target = n;
        if ((1+k)*k/2 > n) return ans;

        vector<int> temp;
        subproblem(1, temp, 0);
        return ans;
    }
};

int main(){
    int k = 3;
    int n = 9;
    Solution S;
    vector<vector<int>> ans = S.combinationSum3(k, n);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}