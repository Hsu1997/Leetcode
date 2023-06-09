#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters.back()) return letters[0];
        int i = 0;
        int j = letters.size()-1;
        while(i < j){
            int mid = i + (j-i)/2;
            if (letters[mid] <= target) i = mid + 1;
            else j = mid;
        }
        return letters[j];
    }
};

int main(){
    // vector<char> letters = {'c','f','j'};
    // char target = 'a';
    // char target = 'c';
    vector<char> letters = {'x','x','y','y'};
    char target = 'z';
    Solution S;
    cout << S.nextGreatestLetter(letters, target) << endl;
    return 0;
}