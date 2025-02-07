#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> ans(q);
        unordered_map<int,int> ball;
        unordered_map<int,int> color_count;
        for (int i = 0; i < q; i++){
            int b = queries[i][0];
            int c = queries[i][1];
            if (ball.find(b) != ball.end()){
                int old_c = ball[b];
                color_count[old_c]--;
                if (color_count[old_c] == 0) color_count.erase(old_c);
            }
            ball[b] = c;
            color_count[c]++;
            ans[i] = color_count.size();
        }
        return ans;
    }
};

int main(){
    int limit = 4;
    vector<vector<int>> queries = {{1,4},{2,5},{1,3},{3,4}};
    // int limit = 4;
    // vector<vector<int>> queries = {{0,1},{1,2},{2,2},{3,4},{4,5}};
    Solution S;
    vector<int> ans = S.queryResults(limit, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}