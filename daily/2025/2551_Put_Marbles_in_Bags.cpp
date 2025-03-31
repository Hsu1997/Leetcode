#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> candidate;
        for (int i = 0; i < n-1; i++){
            candidate.push_back(weights[i]+weights[i+1]);
        }
        sort(candidate.begin(), candidate.end());
        long long ans = 0;
        for (int i = 0; i < k-1; i++){
            ans += candidate[n-2-i] - candidate[i];
        }
        return ans;
    }
};

int main(){
    vector<int> weights = {1,3,5,1};
    int k = 2;
    // vector<int> weights = {1,3};
    // int k = 2;
    Solution S;
    cout << S.putMarbles(weights, k) << endl;
    return 0;
}