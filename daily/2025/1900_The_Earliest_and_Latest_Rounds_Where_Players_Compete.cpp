#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int E[30][30][30] = {0};
    int L[30][30][30] = {0};

    pair<int,int> dp(int n, int f, int s){
        if (E[n][f][s] != 0) return {E[n][f][s],L[n][f][s]};
        if (f + s == n + 1) return {1, 1};
        if (f + s > n + 1){
            auto [x, y] = dp(n, n + 1 - s, n + 1 - f);
            return {E[n][f][s] = x, L[n][f][s] = y};
        }
        // Only (1), (3)
        int mid = (n + 1) / 2;
        int earliest = INT_MAX;
        int latest = INT_MIN;
        if (s <= mid){
            for (int i = 0; i < f; i++){
                for (int j = 0; j < s - f; j++){
                    auto [x, y] = dp(mid, i + 1, i + j + 2);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        }
        else{
            int s_prime = n + 1 - s;
            int middle = (2 * s - n - 1) / 2;
            for (int i = 0; i < f; i++){
                for (int j = 0; j < s_prime - f; j++){
                    auto [x, y] = dp(mid, i + 1, i + j + 2 + middle);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        }
        return {E[n][f][s] = earliest + 1, L[n][f][s] = latest + 1};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        // 1. same side : . * . . . * . . . . | . . . . . . . . . .  => i = [0:f-1], j = [0:s-f-1]
        // 2. on the mid: . * . . . . . . . . * . . . . . . . . . .  => same as (1)
        // 3. diff side : . * . . . . . . . . | . . . * . . . . . .  => i = [0:f-1], j = [(2s-n-1)/2:s-1]
        // 4. diff side : . . . . . . * . . . | . . . . . . . . * .  => equivalent to (3) => s' < f => n + 1 - s < f => f + s > n + 1
        if (firstPlayer > secondPlayer) swap(firstPlayer, secondPlayer);
        auto [earliest, latest] = dp(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};

int main(){
    int n = 11;
    int firstPlayer = 2;
    int secondPlayer = 4;
    // int n = 5;
    // int firstPlayer = 1;
    // int secondPlayer = 5;
    Solution S;
    vector<int> ans = S.earliestAndLatest(n, firstPlayer, secondPlayer);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}