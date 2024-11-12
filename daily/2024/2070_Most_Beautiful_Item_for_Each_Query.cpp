#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int get_idx(vector<vector<int>>& items, int p){
        int k = items.size();
        if (p >= items[k-1][0]) return k-1;
        if (p < items[0][0]) return -1;
        int left = 0;
        int right = k-1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (p >= items[mid][0]){
                ans = max(ans, mid);
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int k = items.size();
        int M = 0;
        for (int i = 0; i < k; i++){
            M = max(M, items[i][1]);
            items[i][1] = M;
        }
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            int idx = get_idx(items, queries[i]);
            if (idx == -1) ans[i] = 0;
            else ans[i] = items[idx][1];
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> queries = {1,2,3,4,5,6};
    // vector<vector<int>> items = {{1,2},{1,2},{1,3},{1,4}};
    // vector<int> queries = {1};
    // vector<vector<int>> items = {{10,1000}};
    // vector<int> queries = {5};
    Solution S;
    vector<int> ans = S.maximumBeauty(items, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}