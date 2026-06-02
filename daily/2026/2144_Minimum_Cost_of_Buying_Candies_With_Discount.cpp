#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int ans = 0;
        int buy = 0;
        for (int i = n - 1; i >= 0; i--){
            if (buy < 2){
                ans += cost[i];
                buy++;
            }
            else{
                buy = 0;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> cost = {1,2,3};
    // vector<int> cost = {6,5,7,9,2,2};
    // vector<int> cost = {5,5};
    Solution S;
    cout << S.minimumCost(cost) << endl;
    return 0;
}



