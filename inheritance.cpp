#include <iostream>
#include <string> 
using namespace std;

//single inheritance - person to student 
class person {
protected:
   string name;
   int age;
   string address;
   
public:
     person() {
        name = "xyz";
        age = 0;
        address = "xyz";
        }
        
        person(string n, int a, string addr) {
           name = n;
           age = a;
           address = addr;
           
        }
          
        void displayperson() {
         cout << "Name: " << name << endl;
         cout << "Age: " << age << endl;
         cout << "Address: " << address << endl;
    }
};

class student : public person {
private:
    int rollnumber;
    float marks;

public:
    student() : person() {
         rollnumber = 0;
         marks = 0;
      }
      
       student(string n, int a, string addr, int roll, float m)
        : person(n, a, addr) {
        rollnumber = roll;
        marks = m;
    }

  void displaystudent() {
     displayperson();
        cout << "Roll No: " << rollnumber << endl;
        cout << "marks: " << marks << endl;
    }
};

int main() {
    student s1("xyz", 18, "pune", 1, 94.5);

    cout << "Student Details:" << endl;
    s1.displaystudent();

    return 0;
}
