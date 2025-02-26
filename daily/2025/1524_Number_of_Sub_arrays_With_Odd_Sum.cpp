#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0;
        int even = 0;
        int ans = 0;
        int mod = 1e9 + 7;
        for (int a : arr){
            if (a % 2 == 0){
                odd = odd;
                even = (1 + even) % mod;
            }
            else{
                swap(odd, even);
                odd = (odd + 1) % mod;
            }
            ans = (ans + odd) % mod;
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1,3,5};
    // vector<int> arr = {2,4,6};
    // vector<int> arr = {1,2,3,4,5,6,7};
    Solution S;
    cout << S.numOfSubarrays(arr) << endl;
    return 0;
}