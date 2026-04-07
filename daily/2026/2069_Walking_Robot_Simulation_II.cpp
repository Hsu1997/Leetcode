#include <iostream>
#include <vector>

using namespace std;

class Robot {
public:
    int accStep;
    int w;
    int h;
    int cycle;
    Robot(int width, int height) {
        accStep = 0;
        w = width;
        h = height;
        cycle = 2 * (w + h - 2);
    }
    
    void step(int num) {
        accStep += num;
    }
    
    vector<int> getPos() {
        int d = accStep % cycle;
        if (d < w) return {d, 0};
        else if (d < w + h - 1) return {w-1, d+1-w};
        else if (d < w + h + w - 2) return {w + w + h - 3 - d, h - 1};
        else return {0, cycle - d};
    }
    
    string getDir() {
        if (accStep == 0) return "East";
        int d = accStep % cycle;
        if (d == 0) return "South";
        // E : [1, w)
        // N : [w, w + h)
        // W : [w + h, w + h + w)
        // S : [w + h + w, w + h + w + h)
        if (d < w) return "East";
        else if (d < w - 1 + h) return "North";
        else if (d < w + h + w - 2) return "West";
        else return "South";
    }
};

int main(){
    // * Your Robot object will be instantiated and called as such:
    // * Robot* obj = new Robot(width, height);
    // * obj->step(num);
    // * vector<int> param_2 = obj->getPos();
    // * string param_3 = obj->getDir();
    // int width = 6;
    // int height = 3;
    // Robot* obj = new Robot(width, height);
    // obj->step(2);
    // obj->step(2);
    // cout << obj->getPos()[0] << " " << obj->getPos()[1] << endl;
    // cout << obj->getDir() << endl;
    // obj->step(2);
    // obj->step(1);
    // obj->step(4);
    // cout << obj->getPos()[0] << " " << obj->getPos()[1] << endl;
    // cout << obj->getDir() << endl;
    int width = 8;
    int height = 2;
    Robot* obj = new Robot(width, height);
    obj->step(17);
    cout << obj->getPos()[0] << " " << obj->getPos()[1] << endl;
    cout << obj->getDir() << endl;
    obj->step(21);
    cout << obj->getPos()[0] << " " << obj->getPos()[1] << endl;
    cout << obj->getDir() << endl;
    obj->step(22);
    obj->step(34);
    cout << obj->getPos()[0] << " " << obj->getPos()[1] << endl;
    cout << obj->getDir() << endl;
    obj->step(1);
    obj->step(46);
    obj->step(35);
    cout << obj->getPos()[0] << " " << obj->getPos()[1] << endl;
    cout << obj->getDir() << endl;
    obj->step(44);
    obj->step(14);
    obj->step(31);
    cout << obj->getPos()[0] << " " << obj->getPos()[1] << endl;
    cout << obj->getDir() << endl;
    obj->step(50);
    return 0;
}