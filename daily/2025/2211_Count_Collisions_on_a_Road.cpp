#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.length();
        int ans = directions.length();
        for (int i = 0; i < n; i++){
            if (directions[i] == 'L') ans--;
            else break;
        }
        for (int i = n - 1; i >= 0; i--){
            if (directions[i] == 'R') ans--;
            else break;
        }
        for (char c : directions){
            if (c == 'S') ans--;
        }
        return ans;
    }
};

int main(){
    string directions = "RLRSLL";
    // string directions = "LLRR";
    Solution S;
    cout << S.countCollisions(directions) << endl;
    return 0;
}