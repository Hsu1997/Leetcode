#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int acc = 0;
        for (int i = 0; i < n; i++) if (grumpy[i] == 0) acc += customers[i];
        // cout << "acc = " << acc << endl;
        int changed = 0;
        for (int i = 0; i < minutes; i++) if (grumpy[i]) changed += customers[i];
        // cout << "changed = " << changed << endl;
        int temp = changed;
        for (int i = minutes; i < n; i++){
            if (grumpy[i - minutes]) temp -= customers[i - minutes];
            if (grumpy[i]) temp += customers[i];
            // cout << "changed = " << temp << endl;
            changed = max(changed, temp);
        }
        return acc + changed;
    }
};

int main(){
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    // vector<int> customers = {1};
    // vector<int> grumpy = {0};
    // int minutes = 1;
    Solution S;
    cout << S.maxSatisfied(customers, grumpy, minutes) << endl;
    return 0;
}