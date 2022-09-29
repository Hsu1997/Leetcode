#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() == k) return arr;

        vector<int> ans;
        int i = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int j = i - 1;
        // cout << j << " " << i << endl;
        while(ans.size() < k && j >= 0 && i < arr.size()){
            if (x - arr[j] > arr[i] - x){
                ans.push_back(arr[i]);
                i++;
            }
            else{
                ans.emplace(ans.begin(), arr[j]);
                j--;
            }
        }
        // cout << j << " " << i << endl;
        if (j == -1) while(ans.size() < k) ans.push_back(arr[i]), i++;
        if (i == arr.size()) while(ans.size() < k) ans.emplace(ans.begin(), arr[j]), j--;
        return ans;
    }
};

int main(){
    // vector<int> arr = {1,2,3,4,5};
    // int k = 4;
    // int x = -1;
    vector<int> arr = {0,1,2,2,2,3,6,8,8,9};
    int k = 5;
    int x = 9;
    Solution S;
    vector<int> ans = S.findClosestElements(arr, k, x);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}