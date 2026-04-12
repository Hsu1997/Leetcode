#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int cost(pair<int,int>& origin, pair<int,int>& destination){
        int ls = origin.first;
        int rs = origin.second;
        int le = destination.first;
        int re = destination.second;
        if ((ls != le) && (rs != re)) return -1;
        int start = (ls == le)? rs : ls;
        int end = (ls == le)? re : le;
        if (start != 26 && end == 26) return -1;
        if (start == 26) return 0;
        int rows = start / 6;
        int cols = start % 6;
        int rowe = end / 6;
        int cole = end % 6;
        return abs(rows - rowe) + abs(cols - cole);
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<int> dp(27 * 27, INT_MAX);
        dp[27 * 27 - 1] = 0;
        for (int i = 0; i < n; i++){
            vector<int> temp(27 * 27, INT_MAX);
            int end = word[i] - 'A';
            // left hand type
            for (int k = 0; k < 27; k++){
                pair<int,int> curr = {end, k};
                for (int pre = 0; pre < 27; pre++){
                    pair<int,int> preStatus = {pre, k};
                    if (dp[pre * 27 + k] == INT_MAX) continue;
                    temp[end * 27 + k] = min(temp[end * 27 + k], dp[pre * 27 + k] + cost(preStatus, curr));
                }
            }
            // right hand type
            for (int k = 0; k < 27; k++){
                pair<int,int> curr = {k, end};
                for (int pre = 0; pre < 27; pre++){
                    pair<int,int> preStatus = {k, pre};
                    if (dp[k * 27 + pre] == INT_MAX) continue;
                    temp[k * 27 + end] = min(temp[k * 27 + end], dp[k * 27 + pre] + cost(preStatus, curr));
                }
            }
            swap(dp, temp);
        }
        int ans = INT_MAX;
        for (int i = 0; i < 27 * 27; i++) ans = min(ans, dp[i]);
        return ans;
    }
};

int main(){
    string word = "CAKE";
    // string word = "HAPPY";
    // string word = "SHH";
    // string word = "WQIQZ";
    Solution S;
    cout << S.minimumDistance(word) << endl;
    return 0;
}