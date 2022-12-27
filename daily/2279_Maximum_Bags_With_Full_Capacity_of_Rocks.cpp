#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans = 0;
        for (int i = 0; i < capacity.size(); i++){
            capacity[i] -= rocks[i];
            if (capacity[i] == 0) ans++;
        }
        sort(capacity.begin(), capacity.end());
        // for (auto i : capacity) cout << i << " ";
        // cout << endl;
        for (auto i : capacity){
            if (i == 0) continue;
            if (additionalRocks >= i) additionalRocks -= i, ans++;
            else return ans;
        }
        return ans;
    }
};

int main(){
    vector<int> capacity = {2,3,4,5};
    vector<int> rocks = {1,2,4,4};
    int additionalRocks = 2;
    // vector<int> capacity = {10,2,2};
    // vector<int> rocks = {2,2,0};
    // int additionalRocks = 100;
    // vector<int> capacity = {10,2,2,3,5,6,2,1};
    // vector<int> rocks = {2,2,0,1,1,1,2,0};
    // int additionalRocks = 10;
    Solution S;
    cout << S.maximumBags(capacity, rocks, additionalRocks) << endl;
    return 0;
}