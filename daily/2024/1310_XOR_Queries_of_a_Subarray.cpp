#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) prefix[i] = arr[i] ^ prefix[i-1];
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++){
            if (queries[i][0] == 0) ans.push_back(prefix[queries[i][1]]);
            else ans.push_back(prefix[queries[i][1]] ^ prefix[queries[i][0] - 1]);
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    // vector<int> arr = {4,8,2,10};
    // vector<vector<int>> queries = {{2,3},{1,3},{0,0},{0,3}};
    Solution S;
    vector<int> ans = S.xorQueries(arr, queries);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}