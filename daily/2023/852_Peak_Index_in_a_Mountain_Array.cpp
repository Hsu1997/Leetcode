#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if (arr[mid] < arr[mid+1]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

int main(){
    vector<int> arr = {0,1,0};
    // vector<int> arr = {0,2,1,0};
    Solution S;
    cout << S.peakIndexInMountainArray(arr) << endl;
    return 0;
}