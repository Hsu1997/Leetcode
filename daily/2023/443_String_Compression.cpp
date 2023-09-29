#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        // if (n == 1) return 1;
        int res = 0;
        int i = 0;
        while(i < n){
            int cnt = 1;
            while(i + cnt < n && chars[i + cnt] == chars[i]) cnt++;
            chars[res++] = chars[i];
            if (cnt > 1){
                for (char c : to_string(cnt)) chars[res++] = c;
            }
            i += cnt;
        }
        return res;
    }
};

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    // vector<char> chars = {'a'};
    // vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    Solution S;
    cout << S.compress(chars) << endl;
    return 0;
}