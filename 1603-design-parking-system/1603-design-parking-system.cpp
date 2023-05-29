class ParkingSystem {
private:
    int slots[3] = {0};
public:
    ParkingSystem(int big, int medium, int small) {
        this->slots[0] = big;
        this->slots[1] = medium;
        this->slots[2] = small;
    }
    
    bool addCar(int carType) {
        if(this->slots[carType - 1]-- <= 0) {
            return false;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */