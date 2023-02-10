#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n < 3) return n;
        int l = 0, r = 1, lacc = 1, racc = 0;
        while(r < n && fruits[r] == fruits[l]) r++;
        if (r == n) return n;
        int lnum = fruits[l], rnum = fruits[r];
        lacc = r;
        racc = 1;
        while(r+1 < n && (fruits[r+1] == lnum || fruits[r+1] == rnum)){
            r++;
            if (fruits[r] == lnum) lacc++;
            else racc++;
        }
        int ans = r - l + 1;
        
        // cout << "l = " << lnum << ", r = " << rnum << " [" << l << "," << r  << "] : " << r-l+1 << endl;
        
        while(r < n){
            while(fruits[l] == lnum){
                lacc--;
                l++;
            }
            swap(lnum, rnum);
            swap(lacc, racc);
            if (racc == 0){
                r++;
                if (r == n) return ans;
                racc = 1;
                rnum = fruits[r];
            }
            
            while(r+1 < n && (fruits[r+1] == lnum || fruits[r+1] == rnum)){
                r++;
                if (fruits[r] == lnum) lacc++;
                else racc++;
            }
            // cout << "l = " << lnum << ", r = " << rnum << " [" << l << "," << r  << "] : " << r-l+1 << endl;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

int main(){
    // vector<int> fruits = {1,2,1};
    // vector<int> fruits = {0,1,2,2};
    // vector<int> fruits = {1,2,3,2,2};
    // vector<int> fruits = {1,1,2,2,2,2,2,2,1,2};
    vector<int> fruits = {1,1,6,5,6,6,1,1,1,1};
    Solution S;
    cout << S.totalFruit(fruits) << endl;
    return 0;
}