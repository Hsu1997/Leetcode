#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = countAndSay(n-1);
        int count = 1;
        string ans;
        for (int i = 0; i < prev.length(); i++){
            if (i < prev.length() - 1 && prev[i] == prev[i+1]){
                count++;
            }
            else{
                ans += to_string(count) + to_string(prev[i] - '0');
                count = 1;
            }
        }
        return ans;
    }
};

int main(){
    int n = 2;
    Solution S;
    for (int i = 1; i < 11; i++){
        cout << i << " : " << S.countAndSay(i) << endl;
    }
    return 0;
}