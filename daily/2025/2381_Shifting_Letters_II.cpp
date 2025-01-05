#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> d(n+1, 0);
        for (auto v : shifts){
            int start = v[0];
            int end = v[1];
            int dir = (v[2] == 0)? -1 : 1;
            d[start] += dir;
            d[end+1] -= dir;
        }
        int acc = 0;
        for (int i = 0; i < n; i++){
            acc += d[i];
            int curr = s[i] - 'a';
            curr = ((curr + acc) % 26 + 26) % 26;
            s[i] = 'a' + curr;
        }
        return s;
    }
};

int main(){
    string s = "abc";
    vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};
    // string s = "dztz";
    // vector<vector<int>> shifts = {{0,0,0},{1,1,1}};
    Solution S;
    cout << S.shiftingLetters(s, shifts) << endl;
    return 0;
}