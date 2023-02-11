#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool mycompare(pair<int,int> a, pair<int,int> b){
        if (a.first != b.first) return a.first < b.first;
        else return a.second < b.second;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> dp(n,0);
        vector<pair<int,int>> player;
        for (int i = 0; i < n; i++){
            player.push_back({ages[i],scores[i]});
        }
        sort(player.begin(), player.end(), mycompare);
        // for (auto i : player) cout << i.first << " " << i.second << endl;

        int max_ans = 0;
        for (int i = 0; i < n; i++){
            int threshold = player[i].second;
            int take = 0;
            for (int j = 0; j < i; j++){
                if (player[j].second <= threshold) take = max(take, dp[j]);
            }
            dp[i] = take + threshold;
            max_ans = max(max_ans, dp[i]);
        }

        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        
        return max_ans;
    }
};

int main(){
    // vector<int> scores = {1,3,5,10,15};
    // vector<int> ages = {1,2,3,4,5};
    // vector<int> scores = {4,5,6,5};
    // vector<int> ages = {2,1,2,1};
    // vector<int> scores = {1,2,3,5};
    // vector<int> ages = {8,9,10,1};
    vector<int> scores = {1,1,1,1,1,1,1,1,1,1};
    vector<int> ages = {811,364,124,873,790,656,581,446,885,134};
    // vector<int> scores = {1,3,7,3,2,4,10,7,5};
    // vector<int> ages = {4,5,2,1,1,2,4,1,4};
    Solution S;
    cout << S.bestTeamScore(scores, ages) << endl;
    return 0;
}