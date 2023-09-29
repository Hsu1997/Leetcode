#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Union_find {
public:
    Union_find(int n){
        u = vector<int>(n);
        rank = vector<int>(n, 0);
        iota(u.begin(), u.end(), 0);
    }
    
    int find(int n){
        if (u[n] == n) return n;
        return u[n] = find(u[n]);
    }

    void combine(int i, int j){
        int x = rank[i];
        int y = rank[j];
        if (x == y){
            u[find(j)] = find(i);
            rank[find(i)]++;
        }
        else if (x < y) u[find(i)] = find(j);
        else u[find(j)] = find(i);
    }

private:
    vector<int> u;
    vector<int> rank;
};

bool compare(vector<int>&a, vector<int>& b){
    return a.back() < b.back();
}

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), compare);

        vector<vector<int>> sorted_queries;
        for (int i = 0; i < queries.size(); i++){
            sorted_queries.push_back({i});
            sorted_queries[i].insert(sorted_queries[i].end(), queries[i].begin(), queries[i].end());
        }
        sort(sorted_queries.begin(), sorted_queries.end(), compare);
        
        Union_find u(n);
        vector<bool> ans(queries.size());
        int now_edge = 0;
        int now_query = 0;
        while(now_query < queries.size()){
            while (now_edge < edgeList.size() && sorted_queries[now_query].back() > edgeList[now_edge].back()){
                u.combine(edgeList[now_edge][0], edgeList[now_edge][1]);
                now_edge++;
            }
            ans[now_query] = (u.find(sorted_queries[now_query][1]) == u.find(sorted_queries[now_query][2]));
            now_query++;
        }
        
        vector<bool> re(queries.size());
        for (int i = 0; i < queries.size(); i++) re[sorted_queries[i][0]] = ans[i];

        return re;
    }
};

int main(){
    // int n = 3;
    // vector<vector<int>> edgeList = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
    // vector<vector<int>> queries = {{0,1,2},{0,2,5}};
    int n = 13;
    vector<vector<int>> edgeList = {{9,1,53},{3,2,66},{12,5,99},{9,7,26},{1,4,78},{11,1,62},{3,10,50},{12,1,71},{12,6,63},{1,10,63},{9,10,88},{9,11,59},{1,4,37},{4,2,63},{0,2,26},{6,12,98},{9,11,99},{4,5,40},{2,8,25},{4,2,35},{8,10,9},{11,9,25},{10,11,11},{7,6,89},{2,4,99},{10,4,63}};
    vector<vector<int>> queries = {{9,7,65},{9,6,1},{4,5,34},{10,8,43},{3,7,76},{4,2,15},{7,6,52},{2,0,50},{7,6,62},{1,0,81},{4,5,35},{0,11,86},{12,5,50},{11,2,2},{9,5,6},{12,0,95},{10,6,9},{9,4,73},{6,10,48},{12,0,91},{9,10,58},{9,8,73},{2,3,44},{7,11,83},{5,3,14},{6,2,33}};
    Solution S;
    vector<bool> ans = S.distanceLimitedPathsExist(n, edgeList, queries);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}