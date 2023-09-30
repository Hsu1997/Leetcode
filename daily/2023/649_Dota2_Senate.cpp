#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int Rban = 0;
        int Dban = 0;
        string s;
        while(true){
            bool same = true;
            for (auto i : senate){
                if (i != senate[0]){
                    same = false;
                    break;
                }
            }
            if (same) return (senate[0] == 'R')? "Radiant" : "Dire";

            for (auto i : senate){
                if (i == 'R'){
                    if (Rban) Rban--;
                    else{
                        Dban++;
                        s.push_back(i);
                    }
                }
                else{
                    if (Dban) Dban--;
                    else{
                        Rban++;
                        s.push_back(i);
                    }
                }
            }
            // cout << s << endl;
            senate = s;
            s.clear();
        }
        return "error";
    }
};

int main(){
    string senate = "RD";
    // string senate = "RDD";
    Solution S;
    cout << S.predictPartyVictory(senate) << endl;
    return 0;
}