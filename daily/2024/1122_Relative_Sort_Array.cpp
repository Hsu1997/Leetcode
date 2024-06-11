#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001);
        vector<int> ans;
        for (auto i : arr1) count[i]++;
        for (auto i : arr2) while(count[i]) ans.push_back(i), count[i]--;
        for (int i = 0; i < count.size(); i++) while(count[i]--) ans.push_back(i);
        return ans;
    }
};

int main(){
    // vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    // vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> arr1 = {28,6,22,8,44,17};
    vector<int> arr2 = {22,28,8,6};
    Solution S;
    vector<int> ans = S.relativeSortArray(arr1, arr2);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}