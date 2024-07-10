#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (string s : logs){
            if (s == "./") continue;
            if (s[0] == '.') ans = max(ans-1, 0);
            else ans++;
        }
        return ans;
    }
};

int main(){
    vector<string> logs = {"d1/","d2/","./","d3/","../","d31/"};
    // vector<string> logs = {"d1/","../","../","../"};
    Solution S;
    cout << S.minOperations(logs) << endl;
    return 0;
}