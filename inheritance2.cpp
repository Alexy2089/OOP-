
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    int year;

public:
    Vehicle() {
        brand = "xyz";
        model = "unknown";
        year = 0;
    }

    Vehicle(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    void displayVehicle() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle {
private:
    string type;
    int range;

public:
    Car() : Vehicle() {
        type = "unknown";
        range = 0;
    }

    Car(string b, string m, int y, string t, int r)
        : Vehicle(b, m, y) {
        type = t;
        range = r;
    }

    void displayCar() {
        displayVehicle();

        cout << "Type: " << type << endl;
        cout << "Range: " << range << endl;
    }
};

int main() {
    Car c1("KIA", "Latest", 2026, "Electric", 200);

    cout << "Vehicle Details:" << endl;
    c1.displayCar();

    return 0;
}
