#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++){
            if (arr[i] > arr[i-1]+1) arr[i] = arr[i-1]+1;
        }
        return arr.back();
    }
};

int main(){
    vector<int> arr = {2,2,1,2,1};
    // vector<int> arr = {100,1,1000};
    // vector<int> arr = {1,2,3,4,5};
    // vector<int> arr = {73,98,9};
    Solution S;
    cout << S.maximumElementAfterDecrementingAndRearranging(arr) << endl;
    return 0;
}