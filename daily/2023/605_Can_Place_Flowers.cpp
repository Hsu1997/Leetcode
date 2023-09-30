#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        bool vaild = true;
        int slot = 0;
        for (int i = 0; i < l-1; i++){
            if (flowerbed[i] == 0){
                if (vaild && !flowerbed[i+1]) slot++;
                vaild = !vaild;
            }
            else vaild = 0;
        }
        if (vaild && !flowerbed[l-1]) slot++;
        return slot >= n;
    }
};

int main(){
    // vector<int> flowerbed = {1,0,0,0,1};
    // int n = 1;
    // int n = 2;
    vector<int> flowerbed = {1,0,0,0,0,1};
    int n = 2;
    Solution S;
    cout << S.canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}