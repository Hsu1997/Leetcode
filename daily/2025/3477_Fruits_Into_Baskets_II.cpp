#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        int n = baskets.size();
        for (int i : fruits){
            bool finded = false;
            for (int j = 0; j < n; j++){
                if (baskets[j] >= i){
                    baskets[j] = 0;
                    finded = true;
                    break;
                }
            }
            if (!finded) unplaced += 1;
        }
        return unplaced;
    }
};

int main(){
    vector<int> fruits = {4,2,5};
    vector<int> baskets = {3,5,4};
    // vector<int> fruits = {3,6,1};
    // vector<int> baskets = {6,4,7};
    Solution S;
    cout << S.numOfUnplacedFruits(fruits, baskets) << endl;
    return 0;
}