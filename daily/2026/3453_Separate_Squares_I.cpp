#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        map<int, double> cnt;
        double total = 0;
        for (auto& square : squares){
            int start = square[1];
            int end = square[1] + square[2];
            double l = square[2];
            cnt[start] += l;
            cnt[end] -= l;
            total += l * l;
        }
        total /= 2;
        double acc = 0;
        int preY = 0;
        // double preL = 0;
        for (auto [y ,l] : cnt){
            if ((y - preY) * acc >= total){
                return preY + total / acc;
            }
            total -= (y - preY) * acc;
            acc += l;
            preY = y;
        }
        return preY + total / acc;
    }
};

int main(){
    vector<vector<int>> squares = {{0,0,1},{2,2,1}};
    // vector<vector<int>> squares = {{0,0,2},{1,1,1}};
    // vector<vector<int>> squares = {{23,29,3},{28,29,4}};
    Solution S;
    cout << S.separateSquares(squares) << endl;
    return 0;
}