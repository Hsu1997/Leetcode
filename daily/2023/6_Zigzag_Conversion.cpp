#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans;
        int n = s.length();
        for (int start = 0; start < n; start += 2 * numRows - 2) ans += s[start];
        for (int r = 1; r < numRows-1; r++){
            int temp = 0;
            while(temp < n){
                temp += r;
                if (temp < n) ans += s[temp];
                temp += 2 * (numRows - r- 1);
                if (temp < n) ans += s[temp];
                temp += r;
            }
        }
        for (int end = numRows-1; end < n; end += 2 * numRows - 2) ans += s[end];
        
        return ans;
    }
};

int main(){
    string s = "PAYPALISHIRING";
    int numRows = 3;
    // string s = "PAYPALISHIRING";
    // int numRows = 4;
    // string s = "a";
    // int numRows = 1;
    Solution S;
    cout << S.convert(s, numRows) << endl;
    return 0;
}