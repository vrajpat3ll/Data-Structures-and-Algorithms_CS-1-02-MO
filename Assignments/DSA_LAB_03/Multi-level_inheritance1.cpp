/*11 April, 2023
Define a class Vehicle that has two member variables maxSpeed and weight and two member functions
setMaxSpeed and setWeight that set the values of these member. Then first derived class Car inherits
from the Vehicle class and adds a member variable numDoors and a member function setNumDoors to set
its value. It also adds a member function which that prints the car's properties, including the drive
properties from the Vehicle class.
The second derived class SportsCar inherits from the Car class and adds a member variable topSpeed and
a member function setTopSpeed to set its value. It also overrides the display function of the Car class
to print the sports car's properties, including the drive properties from the Vehicle and Car classes.

Input Format

Read the value of max speed, weight, number of doors and top speed of a sport car from the console

Constraints
NAN

Output Format
Output the max speed, weight, number of doors and top speed of a sports car.

Sample Input 0

250
1500
2
320
Sample Output 0

Max speed: 250
Weight: 1500
Number of doors: 2
Top speed: 320
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class vehicle
{

public:
    int maxSpeed, weight;
    void setMaxSpeed(int v)
    {
        maxSpeed = v;
    }
    void setWeight(int w)
    {
        weight = w;
    }
};

class car : public vehicle
{

public:
    int NumDoors;
    void setNumDoors(int n)
    {
        NumDoors = n;
    }
    void displaycar(void)
    {
        cout << "Max speed: " << vehicle::maxSpeed << endl;
        cout << "Weight: " << vehicle::weight << endl;
        cout << "Number of doors: " << NumDoors << endl;
    }
};

class SportsCar : public car
{
    int topSpeed;

public:
    void setTopSpeed(int V)
    {
        topSpeed = V;
    }

    void displaycar(void)
    {
        cout << "Max speed: " << vehicle::maxSpeed << endl;
        cout << "Weight: " << vehicle::weight << endl;
        cout << "Number of doors: " << car::NumDoors << endl;
        cout << "Top speed: " << topSpeed << endl;
    }
};

int main()
{
    SportsCar bugati;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bugati.setMaxSpeed(a);
    bugati.setWeight(b);
    bugati.setNumDoors(c);
    bugati.setTopSpeed(d);
    bugati.displaycar();
    return 0;
}