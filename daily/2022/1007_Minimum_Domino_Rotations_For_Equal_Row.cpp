#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        if (n == 0) return -1;
        if (n == 1) return 0;
        
        int option1 = tops[0];
        int option2 = bottoms[0];
        int times_top_op1, times_bottom_op1, times_top_op2, times_bottom_op2;
        times_top_op1 = times_bottom_op1 = times_top_op2 = times_bottom_op2 = 0;
        for (int i = 0; i < n; i++){
            // cout << "round " << i << " : option1 = " << option1 << ", option2 = " << option2 << endl;
            if (option1){
                if (tops[i] == option1) times_top_op1++;
                if (bottoms[i] == option1) times_bottom_op1++;
                if (tops[i] != option1 && bottoms[i] != option1){
                    option1 = 0;
                    times_top_op1 = times_bottom_op1 = 0;
                }
                // cout << "option1 : " << times_top_op1 << ", " << times_bottom_op1 << endl;
             }
            if (option2){
                if (tops[i] == option2) times_top_op2++;
                if (bottoms[i] == option2) times_bottom_op2++;
                if (tops[i] != option2 && bottoms[i] != option2){
                    option2 = 0;
                    times_top_op2 = times_bottom_op2 = 0;
                }
                // cout << "option2 : " << times_top_op2 << ", " << times_bottom_op2 << endl;
            }
            if (!(option1 || option2)) return -1;
        }
        return n - max({times_top_op1, times_bottom_op1, times_top_op2, times_bottom_op2});
    }
};

int main(){
    vector<int> tops  =  {2,1,2,4,2,2};
    vector<int> bottom = {5,2,6,2,3,2};
    Solution S;
    cout << S.minDominoRotations(tops, bottom) << endl;
    return 0;
}