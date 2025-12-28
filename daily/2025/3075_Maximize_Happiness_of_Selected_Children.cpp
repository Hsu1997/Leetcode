#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < k; i++){
            ans += max(0, happiness[i] - i);
        }
        return ans;
    }
};

int main(){
    vector<int> happiness = {1,2,3};
    int k = 2;
    // vector<int> happiness = {1,1,1,1};
    // int k = 2;
    // vector<int> happiness = {2,3,4,5};
    // int k = 2;
    Solution S;
    cout << S.maximumHappinessSum(happiness, k) << endl;
    return 0;
}