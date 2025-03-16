#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        bool canChange(string start, string target) {
            int n = start.length();
            int idx = 0;
            for (int i = 0; i < n; i++){
                if (start[i] == '_') continue;
                else if (start[i] == 'R'){
                    while(idx < i){
                        if (target[idx] == '_') idx++;
                        else return false;
                    }
                    bool find = false;
                    while(idx < n){
                        if (target[idx] == 'R'){
                            idx++;
                            find = true;
                            break;
                        }
                        else if (target[idx] == 'L') return false;
                        else idx++;
                    }
                    if (!find) return false;
                }
                else if (start[i] == 'L'){
                    bool find = false;
                    while(idx <= i){
                        if (target[idx] == 'L'){
                            idx++;
                            find = true;
                            break;
                        }
                        else if (target[idx] == 'R') return false;
                        else idx++;
                    }
                    if (!find) return false;
                }
            }
            while(idx < n){
                if (target[idx++] != '_') return false;
            }
            return true;
        }
    };

int main(){
    string start = "_L__R__R_";
    string end = "L______RR";
    // string start = "R_L_";
    // string end = "__LR";
    // string start = "_R";
    // string end = "R_";
    // string start = "_LL__R__R_";
    // string end = "L___L___RR";
    // string start = "R_L__R__R_";
    // string end = "_L______RR";
    // string start = "_L";
    // string end = "LR";
    // string start = "R";
    // string end = "_";
    Solution S;
    cout << S.canChange(start, end) << endl;
    return 0;
}