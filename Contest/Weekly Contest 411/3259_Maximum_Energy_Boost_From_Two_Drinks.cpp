#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<long long> dpa(2, 0);
        vector<long long> dpb(2, 0);
        dpa[0] = energyDrinkA[0];
        dpb[0] = energyDrinkB[0];
        for (int i = 1; i < n; i++){
            dpa[i % 2] = max(energyDrinkA[i] + dpa[(i + 1) % 2], dpb[(i + 1) % 2]);
            dpb[i % 2] = max(energyDrinkB[i] + dpb[(i + 1) % 2], dpa[(i + 1) % 2]);
        }
        return max(dpa[(n - 1) % 2], dpb[(n - 1) % 2]);
    }
};

int main(){
    vector<int> energyDrinkA = {1,3,1};
    vector<int> energyDrinkB = {3,1,1};
    // vector<int> energyDrinkA = {4,1,1};
    // vector<int> energyDrinkB = {1,1,3};
    Solution S;
    cout << S.maxEnergyBoost(energyDrinkA, energyDrinkB) << endl;
    return 0;
}