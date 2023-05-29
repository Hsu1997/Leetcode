#include <iostream>
#include <vector>

using namespace std;

class ParkingSystem {
public:
    vector<int> slot;

    ParkingSystem(int big, int medium, int small) {
        slot = {big, medium, small};
    }
    
    bool addCar(int carType) {
        return slot[carType-1]-- > 0;
    }
};

int main(){
    ParkingSystem* parkingSystem = new ParkingSystem(1, 1, 0);
    cout << parkingSystem->addCar(1) << endl; // return true because there is 1 available slot for a big car
    cout << parkingSystem->addCar(2) << endl; // return true because there is 1 available slot for a medium car
    cout << parkingSystem->addCar(3) << endl; // return false because there is no available slot for a small car
    cout << parkingSystem->addCar(1) << endl; // return false because there is no available slot for a big car. It is already occupied.

    return 0;
}