#include <iostream>
#include "string"

using namespace std;

class Car
{
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual int getCurrentSpeed() = 0;
    virtual ~Car() {}
};

class SportsCar : public Car
{
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;

public:
    SportsCar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        tyre = "MRF";
    }
    // getter and seter
    int getCurrentSpeed()
    {
        return this->currentSpeed;
    }
    string getTyre()
    {
        return this->tyre;
    }
    // setter

    void setTyre(string tyre)
    {
        this->tyre = tyre;
    }
    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }
    void shiftGear(int gear)
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off cannot shift gear" << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : shifted to  gear " << gear << endl;
    }
    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Engine is off cannot accelerate" << endl;
            return;
        }
        currentSpeed = currentSpeed + 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. " << endl;
    }
    void brake()
    {
        currentSpeed -= 20;
        if (currentSpeed < 0)
            currentSpeed = 20;
        cout << brand << " " << model << " : Breaking! speed is now " << currentSpeed << " km/h. " << endl;
    }
    void stopEngine()
    {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off. " << endl;
    }
};

int main()
{
    Car *mycar = new SportsCar("Ford", "Mustang");
    mycar->startEngine();
    mycar->shiftGear(1);
    mycar->accelerate();
    mycar->shiftGear(2);
    mycar->accelerate();
    mycar->brake();
    mycar->stopEngine();
    cout << "Current spped of my car is " << mycar->getCurrentSpeed() << endl;
}