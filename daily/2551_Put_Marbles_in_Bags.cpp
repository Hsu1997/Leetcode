#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<ll> v;
        for (int i = 0; i < n-1; i++) v.push_back(weights[i] + weights[i+1]);
        sort(v.begin(), v.end());
        ll max_score = 0;
        ll min_score = 0;
        for (int i = 0; i < k-1; i++){
            max_score += v[v.size()-1-i];
            min_score += v[i];
        }
        return max_score - min_score;
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