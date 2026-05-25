#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        queue<int> candidate;
        queue<int> que;
        for (int i = 1; i < n; i++) if (s[i] == '0') candidate.push(i);
        que.push(0);
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            if (curr == n - 1) return true;
            while(!candidate.empty() && curr + maxJump >= candidate.front()){
                if (candidate.front() >= curr + minJump) que.push(candidate.front());
                candidate.pop();
            }
        }
        return false;
    }
};

int main(){
    string s = "011010";
    int minJump = 2;
    int maxJump = 3;
    // string s = "01101110";
    // int minJump = 2;
    // int maxJump = 3;
    Solution S;
    cout << S.canReach(s, minJump, maxJump) << endl;
    return 0;
}