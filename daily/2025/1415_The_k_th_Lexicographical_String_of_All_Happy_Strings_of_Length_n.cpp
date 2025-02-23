#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n-1));
        if (k > total) return "";
        string ans(n, 'a');
        total = (1 << (n-1));
        k--;
        ans[0] = 'a' + (k / total);
        k %= total;
        unordered_map<char, char> nextSmallest = {{'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        unordered_map<char, char> nextGreatest = {{'a', 'c'}, {'b', 'c'}, {'c', 'b'}};
        for (int i = 1; i < n; i++){
            total = (1 << (n-1-i));
            if (k / total == 0) ans[i] = nextSmallest[ans[i-1]];
            else ans[i] = nextGreatest[ans[i-1]];
            k %= total;
        }
        return ans;
    }
};

int main(){
    int n = 1;
    int k = 3;
    // int n = 1;
    // int k = 4;
    // int n = 3;
    // int k = 9;
    // int n = 10;
    // int k = 100;
    Solution S;
    cout << S.getHappyString(n, k) << endl;
    return 0;
}