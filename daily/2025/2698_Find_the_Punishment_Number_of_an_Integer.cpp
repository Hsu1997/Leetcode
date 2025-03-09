#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++){
            string s = to_string(i * i);
            if (punishment(s, 0, 0, 0, i)) ans += i * i;
        }
        return ans;
    }
    bool punishment(string& s, int pos, int curr, int sum, int target){
        if (curr + sum > target) return false;
        if (pos == s.length()) return (sum + curr == target);
        int curr_num = s[pos] - '0';
        return punishment(s, pos+1, curr_num, sum + curr, target) || punishment(s, pos+1, curr*10 + curr_num, sum, target);
    }
};

int main(){
    int n = 10;
    // int n = 37;
    // int n = 1000;
    Solution S;
    cout << S.punishmentNumber(n) << endl;
    return 0;
}