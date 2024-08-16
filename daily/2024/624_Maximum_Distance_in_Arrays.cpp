#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int largest = -1;
        int second_largest = -1;
        int smallest = -1;
        int second_smallest = -1;
        for (int i = 0; i < m; i++){
            int temp_largest = arrays[i].back();
            int temp_smallest = arrays[i][0];
            if (largest == -1) largest = i;
            else if (second_largest == -1){
                if (temp_largest > arrays[largest].back()) second_largest = largest, largest = i;
                else second_largest = i;
            }
            else{
                if (temp_largest > arrays[largest].back()) second_largest = largest, largest = i;
                else if (temp_largest > arrays[second_largest].back()) second_largest = i;
            }
            if (smallest == -1) smallest = i;
            else if (second_smallest == -1){
                if (temp_smallest < arrays[smallest][0]) second_smallest = smallest, smallest = i;
                else second_smallest = i;
            }
            else{
                if (temp_smallest < arrays[smallest][0]) second_smallest = smallest, smallest = i;
                else if (temp_smallest < arrays[second_smallest][0]) second_smallest = i;
            }
        }
        if (largest != smallest) return arrays[largest].back() - arrays[smallest][0];
        int option1 = arrays[largest].back() - arrays[second_smallest][0];
        int option2 = arrays[second_largest].back() - arrays[smallest][0];
        return (option1 > option2)? option1 : option2;
    }
};

int main(){
    // vector<vector<int>> arrays = {{1,2,3},{4,5},{1,2,3}};
    vector<vector<int>> arrays = {{1},{1}};
    Solution S;
    cout << S.maxDistance(arrays) << endl;
    return 0;
}