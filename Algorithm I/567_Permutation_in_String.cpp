#include <iostream>
#include <vector>

using namespace std;

void print(int array[], int n){
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int target_len = s1.length();
        int now_len = 0;
        int target[26] {0};
        int now[26] {0};
        for (auto &c : s1){
            target[c-97]++;
        }
        // print(target, 26);

        string::iterator pointer = s2.begin();

        for (string::iterator c = s2.begin(); c != s2.end(); c++){
            // cout << "now is " <<  *c << endl;
            if (target[(int)*c-97] != 0 && now[(int)*c-97] < target[(int)*c-97]){
                now[(int)*c-97]++;
                now_len++;
                // cout << "-add to " << now_len << endl;
                // print(now, 26);
                if ( now_len == target_len) return true;
            }
            else if (target[(int)*c-97] == 0){
                now_len = 0;
                while(target[(int)*pointer-97] != 0 ){
                    now[(int)*pointer-97]--;
                    pointer++;
                }
                pointer = c;
                pointer++;
                // cout << "type 2 " << endl;
                // print(now, 26);
            }
            else{
                now[(int)*c-97]++;
                now_len++;
                while( target[(int)*pointer-97] == 0 ) pointer++;
                while( now[(int)*c-97] > target[(int)*c-97]){
                    now[(int)*pointer-97]--;
                    now_len--;
                    pointer++;
                }
                // cout << "type 3 " << endl;
                // print(now, 26);
            }
        }
        return false;
    }
};

int main(){
    string s1 = "ky";
    string s2 = "ainwkckifykxlribaypk";
    Solution A;
    cout << A.checkInclusion(s1, s2) << endl;

    // a~z : 97~122 (-97)
    // for (int i = 97; i < 123; i++) cout << i << " : " << (char)i << endl;
    return 0;
}