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
        vector<unordered_map<int,int>> m(n);
        vector<int> acc_arr(n);
        acc_arr[0] = arr[0];
        for (int i = 1; i < n; i++) acc_arr[i] = acc_arr[i-1] ^ arr[i];
        // for (auto i : acc_arr) cout << i << " ";
        // cout << endl;
        m[0][arr[0]]++;
        for (int i = 1; i < n; i++){
            m[i][acc_arr[i]]++;
            for (int j = 0; j < i; j++){
                m[i][acc_arr[i]^acc_arr[j]]++;
                ans += m[j][acc_arr[i]^acc_arr[j]];
            }
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