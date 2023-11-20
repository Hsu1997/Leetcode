#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int metal = 0;
        int paper = 0;
        int glass = 0;
        int last_metal_time = -1;
        int last_paper_time = -1;
        int last_glass_time = -1;
        for (int i = 0; i < garbage.size(); i++){
            for (auto c : garbage[i]){
                if (c == 'G'){
                    glass++;
                    last_glass_time = i;
                }
                else if (c == 'P'){
                    paper++;
                    last_paper_time = i;
                }
                else{
                    metal++;
                    last_metal_time = i;
                }
            }
        }
        // cout << metal << " " << paper << " " << glass << endl;
        // cout << last_metal_time << " " << last_paper_time << " " << last_glass_time << endl;
        int ans = metal + paper + glass;
        if (last_glass_time != -1) for (int i = 0; i < last_glass_time; i++) ans += travel[i];
        if (last_paper_time != -1) for (int i = 0; i < last_paper_time; i++) ans += travel[i];
        if (last_metal_time != -1) for (int i = 0; i < last_metal_time; i++) ans += travel[i];
        return ans;
    }
};

int main(){
    vector<string> garbage = {"G","P","GP","GG"};
    vector<int> travel = {2,4,3};
    // vector<string> garbage = {"MMM","PGM","GP"};
    // vector<int> travel = {3,10};
    Solution S;
    cout << S.garbageCollection(garbage, travel) << endl;
    return 0;
}