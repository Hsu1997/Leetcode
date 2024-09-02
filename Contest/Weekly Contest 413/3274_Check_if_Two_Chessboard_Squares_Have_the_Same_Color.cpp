#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        // return (abs((coordinate1[0]-'a') - (coordinate2[0]-'a')) + abs((coordinate1[1]-'0') - (coordinate2[1]-'0'))) % 2 == 0;
        bool c1 = ((coordinate1[0]-'a') % 2) ^ ((coordinate1[1]-'0') % 2);
        bool c2 = ((coordinate2[0]-'a') % 2) ^ ((coordinate2[1]-'0') % 2);
        return c1 == c2;
    }
};

int main(){
    string coordinate1 = "a1";
    string coordinate2 = "c3";
    // string coordinate1 = "a1";
    // string coordinate2 = "h3";
    Solution S;
    cout << S.checkTwoChessboards(coordinate1, coordinate2) << endl;
    return 0;
}