#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        int ptr = 0;
        while(s[ptr] == '1') ptr++;
        while(ptr < n){
            if (s[ptr] == '1') return false;
            ptr++;
        }
        return true;
    }
};

int main(){
    string s = "1001";
    // string s = "110";
    // string s = "1";
    Solution S;
    cout << S.checkOnesSegment(s) << endl;
    return 0;
}