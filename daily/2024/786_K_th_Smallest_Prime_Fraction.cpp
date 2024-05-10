#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<float,vector<int>>> f;
        for (int i =0; i < n; i++){
            for (int j = i+1; j < n; j++) f.push_back({(float)arr[i] / arr[j], {arr[i], arr[j]}});
        }
        sort(f.begin(), f.end());
        // for (auto i : f) cout << i.first << " (" << i.second[0] << "," << i.second[1] << ")";
        // cout << endl;
        return f[k-1].second;
    }
};

int main(){
    vector<int> arr = {1,2,3,5};
    int k = 3;
    // vector<int> arr = {1,7};
    // int k = 1;
    Solution S;
    vector<int> ans = S.kthSmallestPrimeFraction(arr, k);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}