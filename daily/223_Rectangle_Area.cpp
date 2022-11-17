#include <iostream>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int length = 0;
        int width = 0;
        if (ax1 <= bx1) length = min(ax2,bx2) - bx1;
        else length = min(ax2,bx2) - ax1;
        if (length <= 0) length = 0;
        
        if (by2 >= ay2) width = ay2 - max(ay1,by1);
        else width = by2 - max(ay1,by1);
        if (width <= 0) width = 0;
        
        return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) -(length * width);
    }
};

int main(){
    // int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2= 9, by2 = 2;
    int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2= 2, by2 = 2;
    Solution S;
    cout << S.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;
    return 0;
}