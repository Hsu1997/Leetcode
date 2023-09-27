#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long count = 0;
        int i = 0;
        while(count < k){
            if (isdigit(s[i])) count *= s[i] - '0';
            else count++;
            i++;
        }
        for (int j = i-1; j >= 0; j--){
            if (isdigit(s[j])){
                count /= (s[j] - '0');
                k %= count;
            }
            else{
                if (k == 0 || k == count) return string(1, s[j]);
                count--;
            }
        }
        return "-";
    }
};

int main(){
    // string s = "leet2code3";
    // int k = 10;
    // string s = "ha22";
    // int k = 5;
    string s = "a2345678999999999999999";
    int k = 1000000000;
    // string s = "czjkk9elaqwiz7s6kgvl4gjixan3ky7jfdg3kyop3husw3fm289thisef8blt7a7zr5v5lhxqpntenvxnmlq7l34ay3jaayikjps";
    // int k = 768077956;
    Solution S;
    cout << S.decodeAtIndex(s, k) << endl;
    return 0;
}