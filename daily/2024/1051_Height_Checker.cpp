#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> weights = heights;
        sort(weights.begin(), weights.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) if (heights[i] != weights[i]) ans++;
        return ans;
    }
};

int main(){
    vector<int> heights = {1,1,4,2,1,3};
    // vector<int> heights = {5,1,2,3,4};
    // vector<int> heights = {1,2,3,4,5};
    Solution S;
    cout << S.heightChecker(heights) << endl;
    return 0;
}