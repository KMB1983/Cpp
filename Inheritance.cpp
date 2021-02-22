#include <iostream>


using namespace std;

class Vehicle{
private:
    int _weight;
protected:
    int _speed;
public:
    Vehicle(int speed, int weight) : _speed(speed), _weight(weight) {}

    void start(){
        cout << "Starting engine\n";
    }

    int getWeight() const {return _weight;}
    void setWeight(const int& weight) {
        _weight = weight;
    }

    int accelarate() {
        std::cout << "Using base class method accelarate\n";
    }

};

class Aeroplane:public Vehicle{
private:
    int _height;
public:
    Aeroplane(int speed, int weight, int height) : Vehicle(speed, weight), _height(height) {};

    void start() {
        Vehicle::start();
        std::cout << "speed: " << _speed << std::endl;
        std::cout << "height: " << _height << std::endl;
        std::cout << "weight: " << getWeight() << std::endl;

    }

    using Vehicle::accelarate; // if we wont to use base class method with no arguments
    void accelarate(int speed) {
        _speed += speed;
    }

};

int main() {

    Aeroplane plane(10, 20, 30);
    plane.start();
    plane.accelarate();
    plane.start();
    plane.accelarate(100);
    plane.start();

    return 0;
}
