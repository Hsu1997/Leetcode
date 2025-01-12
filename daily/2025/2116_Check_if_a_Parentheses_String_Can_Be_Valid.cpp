#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2) return false;
        int open = 0;
        int close = 0;
        for (int i = 0; i < n; i++){
            if (locked[i] == '1'){
                if (s[i] == '(') open++;
                else close++;
            }
        }
        if (open > n/2 || close > n/2) return false;
        int change = n/2 - open;
        int acc = 0;
        for (int i = 0; i < n; i++){
            if (locked[i] == '0'){
                if (change){
                    acc++;
                    change--;
                }
                else acc--;
            }
            else{
                if (s[i] == '(') acc++;
                else acc--;
            }
            if (acc < 0) return false;
        }
        return acc == 0;
    }
};

int main(){
    string s = "))()))";
    string locked = "010100";
    // string s = "()()";
    // string locked = "0000";
    // string s = ")";
    // string locked = "0";
    // string s = "()";
    // string locked = "11";
    // string s = "())(()(()(())()())(())((())(()())((())))))(((((((())(()))))(";
    // string locked = "100011110110011011010111100111011101111110000101001101001111";
    Solution S;
    cout << S.canBeValid(s, locked) << endl;
    return 0;
}