#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> m;
        for (char c : moves) m[c]++;
        return m['L'] == m['R'] and m['U'] == m['D'];
    }
};

int main(){
    string moves = "UD";
    // string moves = "LL";
    Solution S;
    cout << S.judgeCircle(moves) << endl;
    return 0;
}