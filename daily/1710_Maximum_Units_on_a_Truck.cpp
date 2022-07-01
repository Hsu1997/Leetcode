#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool mycompare(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        if (boxTypes.size() == 0 || truckSize == 0) return 0;

        sort(boxTypes.begin(), boxTypes.end(), mycompare);
        int box = 0;
        int ans = 0;
        while(truckSize != 0 && box != boxTypes.size()){
            int temp = min(truckSize, boxTypes[box][0]);
            truckSize -= temp;
            ans += temp * boxTypes[box][1];
            box++;
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> boxTypes = {{1,3},{2,2},{3,1}};
    vector<vector<int>> boxTypes = {{5,10},{2,5},{4,7},{3,9}};
    int truckSize = 10;
    Solution S;
    cout << S.maximumUnits(boxTypes, truckSize) << endl;
}