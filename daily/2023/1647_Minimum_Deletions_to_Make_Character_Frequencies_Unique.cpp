#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26,0);
        for (auto i : s) count[i-'a']++;
        // for (auto i : count) cout << i << " ";
        // cout << endl;
        priority_queue<int> pq;
        for (auto i : count) if (i > 0) pq.push(i);
        int ans = 0;
        int now = pq.top()+1;
        while (!pq.empty()){
            // cout << pq.top();
            if (now == 0) ans += pq.top();
            else if (pq.top() <= now) now = pq.top()-1;
            else{
                ans += pq.top() - now;
                now = now - 1;
            }
            pq.pop();
            // cout << " now = " << now << ", ans = " << ans << endl;
        }
        return ans;
    }
};

int main(){
    // string s = "aab";
    // string s = "aaabbbcc";
    string s = "ceabaacb";
    Solution S;
    cout << S.minDeletions(s) << endl;
    return 0;
}