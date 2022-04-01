#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j) swap(s[i++], s[j--]);
    }
};

int main(){
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution S;
    S.reverseString(s);
    for (auto i : s) cout << i << " ";
    cout << endl;
    return 0;
}