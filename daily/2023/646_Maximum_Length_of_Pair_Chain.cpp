#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if (a[1] != b[1]) return a[1] <= b[1];
        else return a[0] > b[0];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int ans = 0;
        int time = INT_MIN;
        for (const auto &pair : pairs){
            if (pair[0] > time) ans++, time = pair[1];
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};
    // vector<vector<int>> pairs = {{1,2},{7,8},{4,5}};
    Solution S;
    cout << S.findLongestChain(pairs) << endl;
    return 0;
}