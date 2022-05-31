#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int bit_to_int(string s){
        int ans = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '1') ans += pow(2, s.length() - i - 1);
        }
        return ans;
    }

    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false;

        int count = 0;
        vector<bool> table(pow(2,k), 0);

        for (int i = 0; i < s.length() - k + 1; i++){
            int temp = bit_to_int(s.substr(i,k));
            if (!table[temp]){
                table[temp] = true;
                count++;
                if (count == pow(2,k)) return true;
            }
        }
        return false;
    }
};

int main(){
    string s = "0110";
    int k = 2;
    // string s = "00110110";
    // int k = 2;
    Solution S;
    cout << S.hasAllCodes(s, k) << endl;
    return 0;
}