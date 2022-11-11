#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        if (s.length() < 2) return s;

        string ans;
        for (auto i : s){
            if (ans.back() == i) ans.pop_back();
            else ans += i; 
        }
        
        return ans;
    }
};

int main(){
    Solution S;
    // string s = "abbaca";
    string s = "azxxzy";
    cout << S.removeDuplicates(s) << endl;
    return 0;
}