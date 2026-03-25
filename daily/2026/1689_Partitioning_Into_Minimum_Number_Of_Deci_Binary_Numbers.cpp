#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char c : n){
            ans = max(ans, c - '0');
        }
        return ans;
    }
};

int main(){
    string n = "32";
    // string n = "82734";
    // string n = "27346209830709182346";
    Solution S;
    cout << S.minPartitions(n) << endl;
    return 0;
}