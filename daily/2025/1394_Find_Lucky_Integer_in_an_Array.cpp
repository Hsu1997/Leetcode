#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> cnt;
        for (int i : arr) cnt[i]++;
        int ans = -1;
        for (auto& [val, c] : cnt){
            if (val == c) ans = max(ans, val);
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {2,2,3,4};
    // vector<int> arr = {1,2,2,3,3,3};
    // vector<int> arr = {2,2,2,3,3};
    Solution S;
    cout << S.findLucky(arr) << endl;
    return 0;
}