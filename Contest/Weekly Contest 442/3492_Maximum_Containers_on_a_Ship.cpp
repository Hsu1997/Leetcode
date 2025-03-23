#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        return min(n * n, maxWeight / w);
    }
};

int main(){
    int n = 2;
    int w = 3;
    int maxWeight = 15;
    // int n = 3;
    // int w = 5;
    // int maxWeight = 20;
    Solution S;
    cout << S.maxContainers(n, w, maxWeight) << endl;
    return 0;
}