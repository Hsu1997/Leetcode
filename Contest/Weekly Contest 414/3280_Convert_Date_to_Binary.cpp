#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string to_binary(int i){
        string ans;
        while(i > 0){
            if (i % 2 == 0) ans += '0';
            else ans += '1';
            i /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string convertDateToBinary(string date) {
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);
        string ans;
        ans = to_binary(stoi(year)) + '-' + to_binary(stoi(month)) + '-' + to_binary(stoi(day));
        return ans;
    }
};

int main(){
    string date = "2080-02-29";
    // string date = "1900-01-01";
    Solution S;
    cout << S.convertDateToBinary(date) << endl;
    return 0;
}