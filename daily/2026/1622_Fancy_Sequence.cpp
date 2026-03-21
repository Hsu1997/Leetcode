#include <iostream>
#include <vector>

using namespace std;

class Fancy {
public:
    long long mod;
    long long add;
    long long mul;
    vector<long long> nums;

    Fancy(){
        mod = 1e9 + 7;
        add = 0;
        mul = 1;
    }
    
    void append(int val) {
        long long res = (val - add + mod) % mod;
        long long mulInverse = llpow(mul, mod - 2);
        res = (res * mulInverse) % mod;
        nums.push_back(res);
    }
    
    void addAll(int inc) {
        add = (add + inc) % mod;
    }
    
    void multAll(int m) {
        add = (add * m) % mod;
        mul = (mul * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        return (nums[idx] * mul + add) % mod;

    }
    long long llpow(long long base, long long pow){
        long long res = 1;
        while(pow){
            if (pow % 2 == 1) res = res * base % mod;
            base = (base * base) % mod;
            pow >>= 1;
        }
        return res;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

int main(){
    Fancy* obj = new Fancy();

    // obj->append(2);
    // obj->addAll(3);
    // obj->append(7);
    // obj->multAll(2);
    // cout << obj->getIndex(0) << " ";
    // obj->addAll(3);
    // obj->append(10);
    // obj->multAll(2);
    // cout << obj->getIndex(0) << " ";
    // cout << obj->getIndex(1) << " ";
    // cout << obj->getIndex(2) << " ";
    // cout << endl;
    
    obj->append(3);
    obj->append(7);
    obj->multAll(4);
    obj->addAll(6);
    obj->append(7);
    obj->append(3);
    cout << obj->getIndex(3) << " ";
    obj->multAll(7);
    obj->multAll(5);
    cout << obj->getIndex(2) << " ";
    cout << obj->getIndex(3) << " ";
    obj->addAll(5);
    obj->append(8);
    obj->append(10);
    cout << obj->getIndex(1) << " ";
    cout << obj->getIndex(4) << " ";
    cout << endl;
    
    return 0;
}