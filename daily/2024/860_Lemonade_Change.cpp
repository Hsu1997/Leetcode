#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int i : bills){
            if (i == 5) five++;
            else if (i == 10){
                five--, ten++;
                if (five < 0) return false;
            }
            else{
                if (ten > 0 && five > 0) ten--, five--;
                else if (five > 2) five -= 3;
                else return false;
            }
        }
        return true;
    }
};

int main(){
    // vector<int> bills = {5,5,5,10,20};
    vector<int> bills = {5,5,10,10,20};
    Solution S;
    cout << S.lemonadeChange(bills) << endl;
    return 0;
}