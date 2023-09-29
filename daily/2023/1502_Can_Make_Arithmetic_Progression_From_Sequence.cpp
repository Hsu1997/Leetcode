#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for (int i = 2; i < n; i++) if (arr[i] - arr[i-1] != diff) return false;
        return true;
    }
};

int main(){
    vector<int> arr = {3,5,1};
    // vector<int> arr = {1,2,4};
    Solution S;
    cout << S.canMakeArithmeticProgression(arr) << endl;
    return 0;
}