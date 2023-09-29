#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end(), less<int>());
        vector<int> ans;
        for (int i = 0; i < n; i++){
            ans.push_back(m - (lower_bound(potions.begin(), potions.end() ,success / spells[i] + (success % spells[i] > 0)) - potions.begin()));
        }
        return ans;
    }
};

int main(){
    // vector<int> spells = {5,1,3};
    // vector<int> potions = {1,2,3,4,5};
    // long long success = 7;
    vector<int> spells = {3,1,2};
    vector<int> potions = {8,5,8};
    long long success = 16;
    Solution S;
    vector<int> ans = S.successfulPairs(spells, potions, success);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}