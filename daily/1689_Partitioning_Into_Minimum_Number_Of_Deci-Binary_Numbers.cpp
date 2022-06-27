#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int M = 0;
        for (auto i : n) M = max(M, i-'0');
        return M;
        // return *max_element(begin(n), end(n)) - '0';
    }
};

int main(){
    // string n = "32";
    // string n = "82734";
    string n = "27346209830709182346";
    Solution S;
    cout << S.minPartitions(n) << endl;
}