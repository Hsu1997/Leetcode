#include <iostream>
#include <vector>

using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        if (n < 2) return -1;
        int left = 0;
        int right = n-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)) left = mid+1;
            else right = mid;
        }
        int cut = left;
        // cout << "cut = " << cut << endl;
        left = 0;
        right = cut;
        while(left < right){
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) == target) return mid;
            else if (mountainArr.get(mid) < target) left = mid + 1;
            else right = mid - 1;
        }
        if (mountainArr.get(left) == target) return left;
        left = cut;
        right = n - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) == target) return mid;
            else if (mountainArr.get(mid) < target) right = mid;
            else left = mid + 1;
        }
        if (mountainArr.get(left) == target) return left;
        return -1;
    }
};