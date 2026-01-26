#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        int m = INT_MAX;
        for (int i = 1; i < n; i++){
            if (arr[i] - arr[i-1] < m){
                m = arr[i] - arr[i-1];
                ans = {{arr[i-1], arr[i]}};
            }
            else{
                if (arr[i] - arr[i-1] == m){
                    ans.push_back({arr[i-1], arr[i]});
                }
                else continue;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {4,2,1,3};
    // vector<int> arr = {1,3,6,10,15};
    // vector<int> arr = {3,8,-10,23,19,-4,-14,27};
    Solution S;
    vector<vector<int>> ans = S.minimumAbsDifference(arr);
    for (auto i : ans){
        cout << '[' << i[0] << "," << i[1] << "] ";
    }
    cout << endl;
    return 0;
}