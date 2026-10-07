#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;
        for (char c : s){
            if (c == '(') open++;
            else{
                if (open == 0) ans++;
                else open--;
            }
        }
        return ans + open;
    }
};

int main(){
    string s = "())";
    // string s = "(((";
    // string s = "()))((";
    Solution S;
    cout << S.minAddToMakeValid(s) << endl;
    return 0;
}