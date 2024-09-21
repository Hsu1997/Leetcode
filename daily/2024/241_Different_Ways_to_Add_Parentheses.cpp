#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        // if (expression.length() == 0) return {};
        if (expression.length() == 1 || expression.length() == 2) return {stoi(expression)};
        for (int i = 0; i < expression.length(); i++){
            char c = expression[i];
            if (isdigit(c)) continue;
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            for (int l : left){
                for (int r : right){
                    if (expression[i] == '+') results.push_back(l + r);
                    else if (expression[i] == '-') results.push_back(l - r);
                    else results.push_back(l * r);
                }
            }
        }
        return results;
    }
};

// class Solution {
// public:
//     vector<int> diffWaysToCompute(string expression) {
//         vector<int> nums;
//         vector<char> oper;
//         int s = expression.size();
//         int i = 0;
//         while(i < s){
//             if (!isdigit(expression[i])) oper.push_back(expression[i]);
//             else{
//                 int num = expression[i] - '0';
//                 if (i + 1 < s && isdigit(expression[i+1])){
//                     num = num * 10 + (expression[++i] - '0');
//                 }
//                 nums.push_back(num);
//             }
//             i++;
//         }
//         int n = nums.size();
//         if (n == 1) return nums;
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
//         for (int i = 0; i < n; i++) dp[i][i].push_back(nums[i]);
//         for (int len = 2; len <= n; len++){
//             for (int start = 0; start + len - 1 < n; start++){
//                 int end = start + len - 1;
//                 for (int o = start; o < end; o++){
//                     char op = oper[o];
//                     vector<int> left = dp[start][o];
//                     vector<int> right = dp[o+1][end];
//                     for (int l : left){
//                         for (int r : right){
//                             switch (op){
//                                 case '+':
//                                     dp[start][end].push_back(l + r);
//                                     break;
//                                 case '-':
//                                     dp[start][end].push_back(l - r);
//                                     break;
//                                 case '*':
//                                     dp[start][end].push_back(l * r);
//                                     break;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return dp[0][n-1];
//     }
// };

int main(){
    string expression = "2-1-1";
    // string expression = "2*3-4*5";
    Solution S;
    vector<int> ans = S.diffWaysToCompute(expression);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}