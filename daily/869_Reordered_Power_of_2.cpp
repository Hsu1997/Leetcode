#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool is_power_of_2(string s){
        int n = stoi(s);
        return (n & (n-1)) == 0;
    }

    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        do{
            if (s[0] != '0' && is_power_of_2(s)) return true; 
            // cout << "@" <<  s << endl;
        } while (next_permutation(s.begin(), s.end()));
        return false;
    }
};

int main(){
    int n = 4021;
    Solution S;
    cout << S.reorderedPowerOf2(n) << endl;
    return 0;
}