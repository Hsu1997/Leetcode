#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        int n = dominoes.size();
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++){
            int curr = (dominoes[i][0] < dominoes[i][1])? dominoes[i][0] * 10 + dominoes[i][1] : dominoes[i][1] * 10 + dominoes[i][0];
            ans += count[curr];
            count[curr]++;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> dominoes = {{1,2},{2,1},{3,4},{5,6}};
    // vector<vector<int>> dominoes = {{1,2},{1,2},{1,1},{1,2},{2,2}};
    Solution S;
    cout << S.numEquivDominoPairs(dominoes) << endl;
    return 0;
}