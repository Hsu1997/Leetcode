#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int counta = 0;
        int countb = 0;
        for (int i = 1; i < colors.size()-1; i++){
            if (colors[i-1] == colors[i] && colors[i] == colors[i+1]){
                if (colors[i] == 'A') counta++;
                else countb++;
            }
        }
        return counta > countb;
    }
};

int main(){
    string colors = "AAABABB";
    // string colors = "AA";
    // string colors = "ABBBBBBBAAA";
    Solution S;
    cout << S.winnerOfGame(colors) << endl;
    return 0;
}