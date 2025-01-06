#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        int left = 0;
        int right = 0;
        int total = 0;
        int acc = 0;
        for (int i = n-1; i >= 0; i--){
            acc += total;
            if (boxes[i] == '1') total++;
        }
        ans[0] = acc;
        for (int i = 1; i < n; i++){
            if (boxes[i-1] == '1') left++;
            ans[i] = ans[i-1] - (total - left) + left;
        }
        return ans;
    }
};

int main(){
    string boxes = "110";
    // string boxes = "001011";
    Solution S;
    vector<int> ans = S.minOperations(boxes);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}