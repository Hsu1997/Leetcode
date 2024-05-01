#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int count[26][2] = {0};
        vector<int> ans(s.size(), 1);
        for (int i = 0; i < s.size(); i++){
            // start from ?-th
            if (count[s[i]-'a'][0] == 0) count[s[i]-'a'][0] = i+1;
            // end on ?-th
            count[s[i]-'a'][1] = i+1;
        }
        // for (int i = 0; i < 26; i++){
        //     cout << count[i][0] << " " << count[i][1] << endl;
        // }
        for (int i = 0; i < 26; i++){
            int start = count[i][0];
            int end = count[i][1];
            if (start == 0 && end == 0) continue;
            // cout << (char)(i+'a') << " : start = " << start << ", end = " << end << endl; 
            int temp = ans[0];
            vector<int>::iterator ptr1, ptr2;
            ptr1 = ++ans.begin();
            while(temp < start && ptr1 != ans.end()){
                temp += *ptr1;
                // cout << "ptr1 temp = " << temp << endl;
                ptr1++;
            }
            ptr1--;
            // cout << "ptr1 point to " << *ptr1 << endl;
            ptr2 = ptr1 + 1;
            while(temp < end && ptr2 != ans.end()){
                temp += *ptr2;
                // cout << "ptr2 temp = " << temp << endl;
                ptr2++;
            }
            ptr2--;
            // cout << "ptr2 point to " << *ptr2 << endl;
            if (ptr1 == ptr2) continue;
            for (vector<int>::iterator i = ptr1 + 1; i <= ptr2; i++) *ptr1 += *i;
            ans.erase(ptr1+1, ptr2+1);
            // for (auto i : ans) cout << i << " ";
            // cout << endl;
        }
        return ans;
    }
};

int main(){
    string s = "ababcbacadefegdehijhklij";
    // string s = "eccbbbbdec";
    Solution S;
    vector<int> ans = S.partitionLabels(s);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}