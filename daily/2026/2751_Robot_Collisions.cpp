#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> index(n);
        vector<int> pos;
        for (int i = 0; i < n; i++) index[i] = i;
        sort(index.begin(), index.end(), [&](int i, int j){return positions[i] < positions[j];});
        stack<int> sta;
        // stack recording 'R' direction robot
        for (int i = 0; i < n; i++){
            int curr = index[i];
            if (directions[curr] == 'L'){
                while(!sta.empty() && healths[curr] > 0){
                    if (healths[curr] >= healths[sta.top()]){
                        if (healths[curr] == healths[sta.top()]){
                            healths[curr] = 0;
                        }
                        healths[sta.top()] = 0;
                        sta.pop();
                        healths[curr]--;
                    }
                    else{
                        healths[curr] = 0;
                        healths[sta.top()]--;
                    }
                }
                if (healths[curr] > 0) pos.push_back(curr);
            }
            else{
                // direction 'R'
                sta.push(curr);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (healths[i] > 0) ans.push_back(healths[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> positions = {5,4,3,2,1};
    vector<int> healths = {2,17,9,15,10};
    string directions = "RRRRR";
    // vector<int> positions = {3,5,2,6};
    // vector<int> healths = {10,10,15,12};
    // string directions = "RLRL";
    // vector<int> positions = {1,2,5,6};
    // vector<int> healths = {10,10,11,11};
    // string directions = "RLRL";
    Solution S;
    vector<int> ans = S.survivedRobotsHealths(positions, healths, directions);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}