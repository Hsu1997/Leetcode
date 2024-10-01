#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> count(k);
        for (int i : arr) count[((i % k) + k) % k]++;
        for (int i = 1; i <= k / 2; i++){
            if (count[i] != count[k-i]) return false;
        }
        if (k % 2 == 0 && count[k / 2] % 2 == 1) return false; 
        return true;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5,10,6,7,8,9};
    int k = 5;
    // vector<int> arr = {1,2,3,4,5,6};
    // int k = 7;
    // vector<int> arr = {1,2,3,4,5,6};
    // int k = 10;
    Solution S;
    cout << S.canArrange(arr, k) << endl;
    return 0;
}