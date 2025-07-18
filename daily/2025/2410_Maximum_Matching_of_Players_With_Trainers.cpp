#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int n = players.size();
        int m = trainers.size();
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            while(j < m && players[i] > trainers[j]) j++;
            if (j == m) break;
            j++;
            ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> players = {4,7,9};
    vector<int> trainers = {8,2,5,8};
    // vector<int> players = {1,1,1};
    // vector<int> trainers = {10};
    Solution S;
    cout << S.matchPlayersAndTrainers(players, trainers) << endl;
    return 0;
}