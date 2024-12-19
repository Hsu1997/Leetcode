#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++){
            visited[arr[i]] = true;
            bool all_contain = true;
            for (int k = 0; k <= i; k++){
                if (!visited[k]) all_contain = false;
            }
            ans += all_contain;
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