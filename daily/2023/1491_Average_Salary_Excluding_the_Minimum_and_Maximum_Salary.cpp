#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        double total = 0;
        int M = max(salary[0], salary[1]);
        int m = min(salary[0], salary[1]);
        for (int i = 2; i < salary.size(); i++){
            if (salary[i] > M){
                total += M;
                M = salary[i];
            }
            else if (salary[i] < m){
                total += m;
                m = salary[i];
            }
            else total += salary[i];
        }
        return total / ((double)salary.size() - 2);
    }
};

int main(){
    // vector<int> salary = {4000,3000,1000,2000};
    vector<int> salary = {1000,2000,3000};
    Solution S;
    cout << S.average(salary) << endl;
    return 0;
}