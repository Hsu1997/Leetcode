#include <iostream>
#include <vector>
#include <set>

using namespace std;

class SegmentTree{
public:
    SegmentTree(vector<int>& obstacle){
        n = 1;
        while(n <= obstacle.back()) n <<= 1;
        t.resize(n * 2);
        for (int i = 1; i < obstacle.size(); i++){
            t[n + obstacle[i]] = obstacle[i] - obstacle[i-1];
        }
        for (int i = n - 1; i > 0; i--){
            t[i] = max(t[i*2], t[i*2+1]);
        }
    }
    int query(int x, int y){
        x += n;
        y += n;
        int ans = 0;
        while(x <= y){
            if (x & 1) ans = max(ans, t[x++]);
            if (!(y & 1)) ans = max(ans, t[y--]);
            x /= 2;
            y /= 2;
        }
        return ans;
    }
    void modify(int x, int v){
        x += n;
        t[x] = v;
        x /= 2;
        while(x){
            t[x] = max(t[x * 2], t[x * 2 + 1]);
            x /= 2;
        }
    }
private:
    int n;
    vector<int> t;
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<int> obstacle = {0, 50001};
        for (auto& query : queries){
            if (query[0] == 1) obstacle.push_back(query[1]);
        }
        sort(obstacle.begin(), obstacle.end());
        SegmentTree T(obstacle);
        set<int> obstacleSet(obstacle.begin(), obstacle.end());
        int q = queries.size();
        vector<bool> ans;
        for (int i = q - 1; i >= 0; i--){
            if (queries[i][0] == 1){
                int p = queries[i][1];
                auto it = obstacleSet.find(p);
                int left = *prev(it);
                int right = *next(it);
                T.modify(p, 0);
                T.modify(right, right - left);
                obstacleSet.erase(it);
            }
            else{
                int p = queries[i][1];
                auto it = obstacleSet.upper_bound(p);
                int prev_obstacle = *prev(it);
                int max_interval = max(p - prev_obstacle, T.query(0, p));
                ans.push_back(max_interval >= queries[i][2]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    vector<vector<int>> queries = {{1,2},{2,3,3},{2,3,1},{2,2,2}};
    // vector<vector<int>> queries = {{1,7},{2,7,6},{1,2},{2,7,5},{2,7,6}};
    Solution S;
    vector<bool> ans = S.getResults(queries);
    for (bool i : ans) cout << i << " ";
    cout << endl;
    return 0;
}