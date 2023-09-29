#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candy = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for (auto i : candies) ans.push_back(i >= max_candy - extraCandies);
        return ans;
    }
};

int main(){
    vector<int> candies = {2,3,5,1,3};
    int extraCandies = 3;
    // vector<int> candies = {4,2,1,1,2};
    // int extraCandies = 1;
    Solution S;
    vector<bool> ans = S.kidsWithCandies(candies, extraCandies);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}