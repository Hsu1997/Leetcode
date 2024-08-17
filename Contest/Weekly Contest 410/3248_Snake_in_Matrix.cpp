#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans = 0;
        for (string s : commands){
            if (s == "UP") ans -= n;
            else if (s == "RIGHT") ans++;
            else if (s == "DOWN") ans += n;
            else ans--;
        }
        return ans;
    }
};

int main(){
    // int n = 2;
    // vector<string> commands = {"RIGHT","DOWN"};
    int n = 3;
    vector<string> commands = {"DOWN","RIGHT","UP"};
    Solution S;
    cout << S.finalPositionOfSnake(n, commands) << endl;
    return 0;
}