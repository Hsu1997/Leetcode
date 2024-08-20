#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<int,int>>> board_sorted_row(m);
        vector<vector<pair<int,int>>> board_sorted_col(n);
        unordered_set<int> row_set;
        unordered_set<int> col_set;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                board_sorted_row[i].push_back({board[i][j], j});
            }
            sort(board_sorted_row[i].begin(), board_sorted_row[i].end(), [](pair<int,int>& a, pair<int,int>& b){return a.first > b.first;});
            for (int j = 0; j < 3; j++) row_set.insert(i * n + board_sorted_row[i][j].second);
        }
        for (int j = 0; j < n; j++){
            for (int i = 0; i < m; i++){
                board_sorted_col[j].push_back({board[i][j], i});
            }
            sort(board_sorted_col[j].begin(), board_sorted_col[j].end(), [](pair<int,int>& a, pair<int,int>& b){return a.first > b.first;});
            for (int i = 0; i < 3; i++) col_set.insert(board_sorted_col[j][i].second * n + j);
        }
        // for (auto i : row_set) cout << i << " ";
        // cout << endl;
        // for (auto i : col_set) cout << i << " ";
        // cout << endl;
        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>> pq;
        for (auto a : row_set){
            if (col_set.find(a) == col_set.end()) continue;
            int i = a / n;
            int j = a % n;
            pq.push({board[i][j], i, j});
            if (pq.size() > 11) pq.pop();
        }
        vector<tuple<long long,int,int>> v;
        while(!pq.empty()){
            // cout << get<0>(pq.top()) << " " << get<1>(pq.top()) << " " << get<2>(pq.top()) << endl;
            v.push_back(pq.top());
            pq.pop();
        }
        int s = v.size();
        long long ans = LLONG_MIN;
        for (int n1 = 0; n1 < s; n1++){
            for (int n2 = n1 + 1; n2 < s; n2++){
                for (int n3 = n2 + 1; n3 < s; n3++){
                    auto [v1, i1, j1] = v[n1];
                    auto [v2, i2, j2] = v[n2];
                    auto [v3, i3, j3] = v[n3];
                    if (i1 == i2 || i2 == i3 || i1 == i3 || j1 == j2 || j2 == j3 || j1 == j3) continue;
                    ans = max(ans, v1 + v2 + v3);
                }
            }
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> board = {{-3,1,1,1},{-3,1,-3,1},{-3,2,1,1}};
    // vector<vector<int>> board = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> board = {{1,1,1},{1,1,1},{1,1,1}};
    vector<vector<int>> board = {{49685527,202668489,-124061990,-197137708},
                                 {495839479,978987221,-588255976,732922326},
                                 {207406008,-851023502,725053940,311164335},
                                 {-422548014,110352941,302829364,174642760}};
    Solution S;
    cout << S.maximumValueSum(board) << endl;
    return 0;
}