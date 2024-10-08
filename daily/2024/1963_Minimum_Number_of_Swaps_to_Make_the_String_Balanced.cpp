#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int left = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '[') left++;
            else{
                if (left == 0){
                    left++;
                    ans++;
                }
                else left--;
            }
        }
        return ans;
    }
};

int main(){
    string s = "][][";
    // string s = "]]][[[";
    // string s = "[]";
    Solution S;
    cout << S.minSwaps(s) << endl;
    return 0;
}