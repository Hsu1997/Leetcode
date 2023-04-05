#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        vector<int> count(26,0);
        for (auto i : s){
            if (count[i-'a'] == ans) ans++;
            count[i-'a'] = ans;
        }
        return ans;
    }
};

int main(){
    // string s = "abacaba";
    string s = "ssssss";
    Solution S;
    cout << S.partitionString(s) << endl;
    return 0;
}