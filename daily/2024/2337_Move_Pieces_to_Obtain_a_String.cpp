#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int start_idx = 0;
        int target_idx = 0;
        while(start_idx < n || target_idx < n){
            while(start_idx < n && start[start_idx] == '_') start_idx++;
            while(target_idx < n && target[target_idx] == '_') target_idx++;
            if (start_idx == n || target_idx == n) return start_idx == target_idx;
            if ((start[start_idx] != target[target_idx]) || (start[start_idx] == 'L' && target_idx > start_idx) || (start[start_idx] == 'R' && start_idx > target_idx)) return false;
            start_idx++, target_idx++;
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