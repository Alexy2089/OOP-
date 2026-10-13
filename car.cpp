
#include <iosream>
#include <string>
using namespace std;
class Vehicle
{
	protected:
		string brand;
		string model;
		int year;
	public:
		Vehicle()
		{
			brand = "Unknown";
			model = "Unknown";
			year = 0;
		}
		Vehicle(string b, string m, int y)
		{
			brand = b;
			model = m;
			year = y;
		}
		void displayVehicle()
		{
			cout<<"Brand"<<brand<<endl;
			cout<<"Model"<<model<<endl;
			cout<<"Year"<<year<<endl;
		}
};
class Car: public Vehile
{
	protected:
		int numberOfDoors;
		string fuelType;
	public:
		car() : Vehicle()
		{
			numberofDoors = 4;
			fuelType = "Petrol";
		}
		car(string b, string m, int y, int doors, string fuel) : vehicle(b, n, y)
		{
			numberofdoors= doors;
			fuelType = fuel;
		}
		void displayCar()
		{
			displayVehicle();
			cout<<"Number of Doors"<<numberofdoors<endl;
			cout<<"Fuel Type"<<fuelType<endl;
		}
 };
 class ElectricCar : public Car
 {
 	private:
 		int batteryCapacity;
 		int range;
 	public:
 		ElectricCar() : Car()
 		{
 			batteryCapacity = 0;
 			range = 0;
 			
		 }
		 ElectricCar(string b, string m, int y, int doors, string fuel, int battery, int r) : Car(b, n, y, doors, fuel)
		 {
		 	batteryCapacity = battery;
		 	range = r;
		 }
		 void displayElectricCar()
		 {
		 	displayCar;
		 	cout<<"Battery Capacity: "<<batteryCapacity<endl;
		 	cout<<"Range: "<<range<<endl;
		 }
 }
