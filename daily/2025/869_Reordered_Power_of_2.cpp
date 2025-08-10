#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool power_of_two(int n){
        return (n & (n - 1)) == 0;
    }

    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        vector<bool> visited(s.length(), false);
        if (dfs(s, 0, 0, visited)) return true;
        return false;
    }

    bool dfs(string& s, int idx, int curr, vector<bool>& visited){
        if (idx == s.length()) return power_of_two(curr);
        for (int i = 0; i < s.length(); i++){
            if (visited[i] || (idx == 0 && s[i] == '0')) continue;
            visited[i] = true;
            if (dfs(s, idx + 1, curr * 10 + (s[i] - '0'), visited)) return true;
            visited[i] = false;
        }
        return false;
    }
};

int main(){
    int n = 1;
    // int n = 10;
    // int n = 49;
    // int n = 12938412;
    // int n = 1000000000;
    // int n = 923438282;
    // int n = 16;
    Solution S;
    cout << S.reorderedPowerOf2(n) << endl;
    return 0;
}