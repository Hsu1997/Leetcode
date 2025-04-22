#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        vector<bool> visited(n, false);
        int pos = 0;
        long long ans = 0;
        while(pos >= 0 && pos < n && !visited[pos]){
            visited[pos] = true;
            if (instructions[pos] == "add"){
                ans += values[pos];
                pos++;
            }
            else{
                pos += values[pos];
            }
        }
        return ans;
    }
};

int main(){
    vector<string> instructions = {"jump","add","add","jump","add","jump"};
    vector<int> values = {2,1,3,1,-2,-3};
    // vector<string> instructions = {"jump","add","add"};
    // vector<int> values = {3,1,1};
    // vector<string> instructions = {"jump"};
    // vector<int> values = {0};
    Solution S;
    cout << S.calculateScore(instructions, values) << endl;
    return 0;
}