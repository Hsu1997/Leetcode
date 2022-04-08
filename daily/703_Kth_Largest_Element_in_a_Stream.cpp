#include <iostream>
#include <vector>

using namespace std;

class KthLargest{
public:
    vector<int> array;
    int target;

    KthLargest(int k, vector<int>& nums) {
        array = nums;
        target = k;
        sort(array.begin(), array.end(), greater<int>());
        // for (auto i : array) cout << i << " ";
        // cout << endl;
    }
    
    int add(int val) {
        int i = 0;
        int j = array.size()-1;
        while(i <= j){
            int mid = i + (j - i) / 2;
            if (array[mid] < val) j = mid - 1;
            else if (array[mid] > val) i = mid + 1;
            else{
                array.insert(array.begin() + mid, val);
                // for (auto i : array) cout << i << " ";
                // cout << endl;
                return array[target - 1];
            }
        }
        array.insert(array.begin() + i, val);
        // for (auto i : array) cout << i << " ";
        // cout << endl;
        return array[target - 1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(){
    vector<int> nums = {4,5,8,2};
    int k = 3;
    KthLargest* obj = new KthLargest(k, nums);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
    return 0;
}