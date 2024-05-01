#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if (colors.length() < 2) return 0;
        int ans = 0;
        int temp = 0;
        int max_int = 0;

        for (int i = 1; i < colors.length(); i++){
            if (colors[i] == colors[i-1]){
                if (temp == 0){
                    temp = neededTime[i-1];
                    max_int = neededTime[i-1];
                }
                temp += neededTime[i];
                max_int = max(max_int, neededTime[i]);
            }
            else{
                if (temp != 0){
                    ans += (temp - max_int);
                    temp = 0;
                    max_int = 0;
                }
            }
            // cout << temp << " ";
        }
        // cout << endl;
        if (temp != 0) ans += (temp - max_int);
        return ans;
    }
};

int main(){
    // string colors = "abaac";
    // vector<int> neededTime = {1,2,3,4,5};
    // string colors = "abc";
    // vector<int> neededTime = {1,2,3};
    string colors = "aabaa";
    vector<int> neededTime = {1,2,3,4,1};

    Solution S;
    cout << S.minCost(colors, neededTime) << endl;
    return 0;
}