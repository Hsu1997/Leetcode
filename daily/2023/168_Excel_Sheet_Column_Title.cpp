#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string ans;
    string convertToTitle(int columnNumber) {
        if (columnNumber == 0) return "";
        if (columnNumber % 26 == 0) return convertToTitle(columnNumber/26-1)+'Z';
        else return convertToTitle(columnNumber/26)+char('A'+(columnNumber%26)-1);
    }
};

int main(){
    int columnNumber = 701;
    Solution S;
    cout << S.convertToTitle(columnNumber) << endl;
    return 0;
}