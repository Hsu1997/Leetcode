#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int status = 0;
        for (int i = 0; i < n; i++){
            status |= (1 << arr[i]);
            if (status == (1 << (i+1)) - 1) ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {4,3,2,1,0};
    // vector<int> arr = {1,0,2,3,4};
    Solution S;
    cout << S.maxChunksToSorted(arr) << endl;
    return 0;
}