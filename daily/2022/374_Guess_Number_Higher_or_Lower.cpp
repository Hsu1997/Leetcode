#include <iostream>

using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        while(true){
            int mid = l + (r-l)/2;
            int response = guess(mid);
            if (response == 0) return mid;
            if (response < 0) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};