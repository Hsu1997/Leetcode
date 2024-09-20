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

int main(){
    string expression = "2-1-1";
    // string expression = "2*3-4*5";
    Solution S;
    vector<int> ans = S.diffWaysToCompute(expression);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}