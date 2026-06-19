#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++){
            string s = to_string(i);
            int l = s.length();
            for (int j = 1; j < l - 1; j++){
                if ((s[j] < s[j-1] && s[j] < s[j+1]) || (s[j] > s[j-1] && s[j] > s[j+1])) ans++;
            }
        }
        return ans;
    }
};

int main(){
    int num1 = 120;
    int num2 = 130;
    // int num1 = 198;
    // int num2 = 202;
    // int num1 = 4848;
    // int num2 = 4848;
    Solution S;
    cout << S.totalWaviness(num1, num2) << endl;
    return 0;
}