#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;
        int end = n - 2;
        while(end >= 0 && arr[end] <= arr[end+1]) end--;
        if (end == -1) return 0;
        int ans = end + 1;
        for (int start = 1; start < n; start++){
            while(end < n-1 && arr[start-1] > arr[end+1]) end++;
            // cout << start << "-" << end << endl;
            ans = min(ans, end - start + 1);
            if (arr[start] < arr[start-1]) break;
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1,2,3,10,4,2,3,5};
    // vector<int> arr = {5,4,3,2,1};
    // vector<int> arr = {1,2,3};
    Solution S;
    cout << S.findLengthOfShortestSubarray(arr) << endl;
    return 0;
}