#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        map<int, int> m;
        for (auto i : costs) m[i]++;
        // for (auto i : m) cout << i.first << " " << i.second << endl;
        for (auto i : m){
            if (coins >= (long)i.first * (long)i.second) coins -= i.first * i.second, ans += i.second;
            else{
                ans += coins / i.first;
                return ans;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> costs = {1,3,2,4,1};
    int coins = 7;
    // vector<int> costs = {10,6,8,7,7,8};
    // int coins = 5;
    // vector<int> costs = {1,6,3,1,2,5};
    // int coins = 20;
    // vector<int> costs = {1,3,2,4,1,2,2,2,2,2};
    // int coins = 10;
    Solution S;
    cout << S.maxIceCream(costs, coins) << endl;
    return 0;
}