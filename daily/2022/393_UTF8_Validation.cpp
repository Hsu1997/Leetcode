#include <iostream>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        int temp = 0;
        for (auto i : data){
            bitset<8> a(i);
            // cout << a << " : ";
            string b = a.to_string();
            if (count == 0){
                if (b.substr(0,2) == "10") return false;
                int ptr = 0;
                while(b[ptr] == '1') ptr++;
                count = ptr;
                if (count > 4) return false;
                if (count > 0) count--;
            }
            else{
                if (b.substr(0,2) != "10") return false;
                count--;
            }
            // cout << "count = " << count;
            // cout << endl;
        }
        return (count == 0)? true : false;
    }
};

int main(){
    // vector<int> data = {197,130,1};
    vector<int> data = {250,145,145,145,145};
    Solution S;
    cout << S.validUtf8(data) << endl;
    return 0;
}