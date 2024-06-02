#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        while(i < j) swap(s[i++],s[j--]);
    }
};

int main(){
    // vector<char> s = {'h','e','l','l','o'};
    vector<char> s = {'H','a','n','n','a','h'};
    Solution S;
    S.reverseString(s);
    for (auto i : s) cout << i << " ";
    cout << endl;
    return 0;
}
