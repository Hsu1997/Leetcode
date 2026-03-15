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
        string ans(n, ' ');
        int startA = 1;
        int startB = startA + (1 << (n-1));
        int startC = startB + (1 << (n-1));
        // convert to 0-index
        if (k < startB){
            ans[0] = 'a';
            k -= startA;
        }
        else if (k < startC){
            ans[0] = 'b';
            k -= startB;
        }
        else{
            ans[0] = 'c';
            k -= startC;
        }
        unordered_map<char,char> nextSmaller = {{'a','b'},{'b','a'},{'c','a'}};
        unordered_map<char,char> nextGreater = {{'a','c'},{'b','c'},{'c','b'}};
        for (int idx = 1; idx < n; idx++){
            int mid = (1 << (n - 1 - idx));
            if (k < mid) ans[idx] = nextSmaller[ans[idx-1]];
            else{
                ans[idx] = nextGreater[ans[idx-1]];
                k -= mid;
            }
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
    Solution S;
    cout << S.getHappyString(n, k) << endl;
    return 0;
}