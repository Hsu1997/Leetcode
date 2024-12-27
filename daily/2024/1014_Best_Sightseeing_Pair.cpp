#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = INT_MIN;
        int curr = values[0];
        for (int i = 1; i < n; i++){
            ans = max(ans, curr + values[i] - i);
            curr = max(curr, values[i] + i);
        }
        return ans;
    }
};

int main(){
    vector<int> values = {8,1,5,2,6};
    // vector<int> values = {1,2};
    Solution S;
    cout << S.maxScoreSightseeingPair(values) << endl;
    return 0;
}