#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size() - 1;
        if (letters[r] <= target || letters[0] > target) return letters[0];
        while(r - l > 1){
            int mid = l + (r - l) / 2;
            if (letters[mid] > target) r = mid;
            else l = mid;
        }
        return letters[r];
    }
};

int main(){
    vector<char> letters = {'c','f','j'};
    char target = 'a';
    // vector<char> letters = {'c','f','j'};
    // char target = 'c';
    // vector<char> letters = {'x','x','y','y'};
    // char target = 'z';
    Solution S;
    cout << S.nextGreatestLetter(letters, target) << endl;
    return 0;
}