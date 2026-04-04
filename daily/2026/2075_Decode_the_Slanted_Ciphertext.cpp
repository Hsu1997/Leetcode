#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int cols = n / rows;
        string ans;
        auto idx = [&](int i, int j){
            return i * cols + j;
        };
        for (int t = 0; t < cols; t++){
            int r = 0;
            int c = t;
            for (int r = 0, c = t; r < rows && c < cols; r++, c++){
                ans.push_back(encodedText[idx(r, c)]);
            } 
        }
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};

int main(){
    string encodedText = "ch   ie   pr";
    int rows = 3;
    // string encodedText = "iveo    eed   l te   olc";
    // int rows = 4;
    // string encodedText = "coding";
    // int rows = 1;
    // string encodedText = " b  ac";
    // int rows = 2;
    // string encodedText = "iveo    eed   l t    olc";
    // int rows = 4;
    // string encodedText = "whurqonhhaymkrxebpdagccsjvoontnejzqkmqdedwkbjsas t kga kjjchpxkkuraiyvmsx gvvfbkfx yrpydxajzmmelyxy b";
    // int rows = 1;
    Solution S;
    cout << S.decodeCiphertext(encodedText, rows) << endl;
    return 0;
}