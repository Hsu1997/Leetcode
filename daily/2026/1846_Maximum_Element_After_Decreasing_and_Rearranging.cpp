#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < n; i++){
            arr[i] = min(arr[i], arr[i-1] + 1);
        }
        return arr[n-1];
    }
};

int main(){
    vector<int> arr = {2,2,1,2,1};
    // vector<int> arr = {100,1,1000};
    // vector<int> arr = {1,2,3,4,5};
    Solution S;
    cout << S.maximumElementAfterDecrementingAndRearranging(arr) << endl;
    return 0;
}