#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int item_size = strs.size();
        vector<pair<int,int>> item;
        for (string i : strs){
            int zero = 0;
            int one = 0;
            for (char j : i){
                if (j == '0') zero++;
                if (j == '1') one++;
            }
            item.push_back({zero, one});
        }
        // for (auto i : item) cout << "{" << i.first << "," << i.second << "}" << endl;
        
        vector<vector<int>> dp(item_size, vector<int>((m+1) * (n+1), 0));
        int m_item = item[0].first;
        int n_item = item[0].second;
        // cout << m_item << " " << n_item << endl;
        for (int j = 0; j <  (m+1) * (n+1); j++){
            int m_limit = j / (n+1);
            int n_limit = j % (n+1);
            if (m_limit < m_item || n_limit < n_item) dp[0][j] = 0;
            else dp[0][j] = 1;
        }
        for (int i = 0; i < item_size; i++) dp[i][0] = 0;
        for (int i = 1; i < item_size; i++){
            m_item = item[i].first;
            n_item = item[i].second;
            // cout << m_item << "," << n_item << endl;
            for (int j = 1; j < (m+1) * (n+1); j++){
                int m_limit = j / (n+1);
                int n_limit = j % (n+1);
                int not_take = dp[i-1][j];
                int take;
                if (m_limit < m_item || n_limit < n_item) take = -1;
                else{
                    m_limit -= m_item;
                    n_limit -= n_item;
                    take = dp[i-1][m_limit*(n+1)+n_limit] + 1;
                }
                dp[i][j] = max(take, not_take);
            }
        }
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return dp[item_size-1][(m+1)*(n+1)-1];
    }
};

int main(){
    vector<string> strs = {"10","0001","111001","1","0"};
    // vector<string> strs = {"10","0","1"};
    int m = 5;
    int n = 3;
    Solution S;
    cout << S.findMaxForm(strs, m, n) << endl;
    return 0;
}