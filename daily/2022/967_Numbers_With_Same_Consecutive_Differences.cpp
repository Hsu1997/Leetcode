#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    int k;
    vector<int> ans;

    void dfs(int now, int level){
        if (level == n) ans.push_back(now);
        else{
            int up = now % 10 + k;
            int down = now % 10 - k;
            if (up <= 9) dfs(now * 10 + (now % 10 + k), level + 1);
            if (down >= 0 && up != down) dfs(now * 10 + (now % 10 - k), level + 1);
        }
    }

    vector<int> numsSameConsecDiff(int _n, int _k) {
        n = _n;
        k = _k;
        for (int i = 1; i <= 9; i++) dfs(i, 1);

        return ans;
    }
};

int main(){
    // int n = 3;
    // int k = 7;

    int n = 2;
    int k = 0;

    Solution S;
    vector<int> ans = S.numsSameConsecDiff(n, k);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}