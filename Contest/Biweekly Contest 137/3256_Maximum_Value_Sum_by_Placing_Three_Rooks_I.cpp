#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<int,int>>> board_sorted(m);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                board_sorted[i].push_back({board[i][j], j});
            }
            sort(board_sorted[i].begin(), board_sorted[i].end(), [](pair<int,int>& a, pair<int,int>& b){return a.first > b.first;});
        }
        long long ans = LLONG_MIN;
        for (int n1 = 0; n1 < m; n1++){
            for (int d1 = 0; d1 < 3; d1++){
                for (int n2 = n1 + 1; n2 < m; n2++){
                    for (int d2 = 0; d2 < 3; d2++){
                        for (int n3 = n2 + 1; n3 < m; n3++){
                            for (int d3 = 0; d3 < 3; d3++){
                                if (board_sorted[n1][d1].second == board_sorted[n2][d2].second || board_sorted[n1][d1].second == board_sorted[n3][d3].second || board_sorted[n2][d2].second == board_sorted[n3][d3].second) continue;
                                ans = max(ans, (long long)board_sorted[n1][d1].first + board_sorted[n2][d2].first + board_sorted[n3][d3].first);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> board = {{-3,1,1,1},{-3,1,-3,1},{-3,2,1,1}};
    // vector<vector<int>> board = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> board = {{1,1,1},{1,1,1},{1,1,1}};
    Solution S;
    cout << S.maximumValueSum(board) << endl;
    return 0;
}