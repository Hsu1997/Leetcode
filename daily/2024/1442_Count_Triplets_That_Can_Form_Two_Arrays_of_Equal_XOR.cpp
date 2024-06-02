#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;
        int ans = 0;
        int prefix = 0;
        unordered_map<int,int> count, total;
        count[0]++;
        for (int i = 0; i < arr.size(); i++){
            prefix ^= arr[i];
            ans += count[prefix]++ * i - total[prefix];
            total[prefix] += (i + 1);
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {2,3,1,6,7};
    // vector<int> arr = {1,1,1,1,1};
    Solution S;
    cout << S.countTriplets(arr) << endl;
    return 0;
}