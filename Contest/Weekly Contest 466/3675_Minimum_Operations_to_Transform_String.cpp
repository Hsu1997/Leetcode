#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        char min_c = 'z' + 1;
        for (char c : s){
            if (c == 'a') continue;
            min_c = min(min_c, c);
        }
        if (min_c == 'z' + 1) return 0;
        return 'z' - min_c + 1;
    }
};

int main(){
    string s = "yz";
    // string s = "a";
    Solution S;
    cout << S.minOperations(s) << endl;
    return 0;
}