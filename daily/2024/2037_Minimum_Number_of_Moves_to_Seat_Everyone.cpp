#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> cseat(100);
        vector<int> cstudent(100);
        for (int i : seats) cseat[i-1]++;
        for (int i : students) cstudent[i-1]++;
        int i = 0;
        int j = 0;
        int ans = 0;
        for (int r = 0; r < seats.size(); r++){
            while(cseat[i] == 0) i++;
            while(cstudent[j] == 0) j++;
            ans += abs(i - j);
            cseat[i]--, cstudent[j]--;
        }
        return ans;
    }
};

int main(){
    vector<int> seats = {3,1,5};
    vector<int> students = {2,7,4};
    // vector<int> seats = {4,1,5,9};
    // vector<int> students = {1,3,2,6};
    // vector<int> seats = {2,2,6,6};
    // vector<int> students = {1,3,2,6};
    Solution S;
    cout << S.minMovesToSeat(seats, students) << endl;
    return 0;
}