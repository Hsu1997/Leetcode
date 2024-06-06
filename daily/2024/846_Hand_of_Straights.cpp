#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> m;
        for (auto i : hand) m[i]++;
        while(!m.empty()){
            int temp = m.begin()->first;
            for (int i = temp; i < temp + groupSize; i++){
                if (m[i] == 0) return false;
                m[i]--;
                if (m[i] == 0) m.erase(i);
            }
        }
        return true;
    }
};

int main(){
    // vector<int> hand = {1,2,3,6,2,3,4,7,8};
    // int groupSize = 3;
    vector<int> hand = {1,2,3,4,5};
    int groupSize = 4;
    Solution S;
    cout << S.isNStraightHand(hand, groupSize) << endl;
    return 0;
}