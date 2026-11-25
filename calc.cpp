#include <iostream>
#include <string>
usingnamespace std;

//class template for calculator
template <typename T >
class calculator {
private:
     T value1;
     T value2;
 
 public:
       // constructor
       calculator ( T V1, T v2) {
        value1 = v1;
        value2 = v2;
      }
      
      //Arithematic operations
      T add() {
         return value1 + value2;
     }
     
  public:
       T subtract() {
         return value1 - value2;
      }
      
      T multiply() {
          return value1 * value2;
      }
      
      T divide() {
          if ( value2 == 0) {
             throw "Division by zero!";
      }
      return value1 / value2;
     }
     
     // Find larger value
     T findlarger() {
        return (value1 > value2) ? value1: value2;
     }
     
     //Find smaller value
     T find smalller()  {
      return ( value1 < value2) ? value1: value2;
     }
     
     // Display results
     void displayresults() {
       cout << "value1: " << value1 << endl;
       cout << "value2: " << value2 << endl;
       cout << " Addition:" << add() << endl;
       cout << "subtraction: " << substract() << endl;
       cout << "multiplication: " << multiply() << endl;
       try {
             cout << " Division: " << divide () << endl;
           } catch ( const char* msg) {
               cout << "Division error: " << msg << endl;
       }
       
       cout << "Larger value: " << findlarger() << endl;
       cout << " Smalller value: " << findsmaller() << endl;
      }
    };
    
    // specilalization of class template for strng
    template <>
    class calculator<string> {
    private:
        string value1;
        string value2;
        
    public:
        calculator( string v1, string v2) {
         value1 = v1;
         value2 = v2;
     }
      
      void setvalues(string v1, string v2) {
         value1 = v1;
          value2 = v2;
    } 
    
    string add() {
      return value1 + value2;
     } 
     
     string findlarger() {
        return ( value1 > value2) ? value1 : value2;
    }
    
    string findsmaller() {
           return ( value1 < value2) ? value1 : value2;
     }
     
     void displayresult() {
          cout << " value1: " <<  value1 << endl;
          cout << " value2: "  << value2 << endl;
int main () {
    cout << "=====Class template calculator ====="<< endl;

    cout << "\n ----integer calculator ---"<< endl;
    calculator<int>intcalc(10,5);
    intcalc.displayresult();


cout << "\n float calculator ---"<<endl;
calculator<float>floatcalc(3.14,2.71);
floatcalc.displayresult() ;



cout << "\n ----double calculator----"<<endl;
calculator<double>doublecalc(100.5,50.25);
doublecalc.displayresult() ;


cout<<"----string calculator(specialization)---"<<endl;
calculator<string>stringcalc("hello","world");
stringcalc.displayresult();


cout<<"----user input calculator ----"<<endl;
int num1,num2;
cout << "enter two integer:";
cin>>num1>>num2;

calculator<int>usercalc(num1,num2);
usercalc.displayresults();

return 0;
