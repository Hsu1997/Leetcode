#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        int max = 26*n;
        int a_amount = (max-k)/25;
        int remain = k - a_amount;
        ans.insert(ans.end(), a_amount, 'a');
        // for (int i = 0; i < a_amount; i++) ans += 'a';
        if (remain % 26 != 0){
            ans += (remain % 26 + 'a' - 1);
            remain -= remain % 26;
        } 
        ans.insert(ans.end(), remain/26, 'z');
        // for (int i = remain; i > 0; i -= 26){
        //     ans += 'z';
        // } 
        return ans;
    }
};

int main(){
    int n = 5;
    int k = 73;
    Solution S;
    cout << S.getSmallestString(n, k) << endl;
    return 0;
}