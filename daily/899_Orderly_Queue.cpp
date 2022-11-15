#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans = s;
        if (k == 1){
            for (int i = 1; i < s.length(); i++){
                string temp = s.substr(i, s.length()-i) + s.substr(0, i);
                // cout << temp << endl;
                if (ans.compare(temp) > 0) ans = temp;
            }
        }
        else sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution S;
    // string s = "cba";
    // int k = 1;
    string s = "baaca";
    int k = 3;
    cout << S.orderlyQueue(s, k) << endl;
    return 0;
}