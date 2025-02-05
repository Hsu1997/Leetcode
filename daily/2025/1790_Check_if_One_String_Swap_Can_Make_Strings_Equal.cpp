#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int diff = 0;
        vector<int> indices(2);
        for (int i = 0; i < n; i++){
            if (s1[i] != s2[i]){
                if (diff == 2) return false;
                indices[diff] = i;
                diff++;
            }
        }
        if (s1[indices[0]] != s2[indices[1]] || s1[indices[1]] != s2[indices[0]]) return false;
        return true;
    }
};

int main(){
    string s1 = "bank";
    string s2 = "kanb";
    // string s1 = "attack";
    // string s2 = "defend";
    // string s1 = "kelb";
    // string s2 = "kelb";
    Solution S;
    cout << S.areAlmostEqual(s1, s2) << endl;
    return 0;
}