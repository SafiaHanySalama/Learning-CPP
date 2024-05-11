/**
 * Which constructor and destructor is called first in inheritance?
*/
#include <iostream>
using namespace std;

class Base{
    int x;
    public:
        Base(): x(10){
            cout << "Base Constructor Base():x(10)" << endl;
        }
        Base(int x): x{x}{
            cout << "Base Constructor Base(int x):x(x)" << endl;
        }
        ~Base(){
            cout << "Base Destructor" << endl;
        }
        void setX(int i){
            x = i;
        }
        int getX(){
            return x;
        }
};
class Derived: public Base{
    int y;
    public:
        Derived(): y(20){
            cout << "Derived Constructor" << endl;
        }
        Derived(int y): Base(y), y{y}{
            cout << "Derived Constructor Derived(int y):y(y)" << endl;
        }
        ~Derived(){
            cout << "Derived Destructor" << endl;
        }
        void setY(int i){
            y = i;
        }
        int getY(){
            return y;
        }
};
int main(){
    
    Derived b{5}; //Default constructor of base class is called not parameterized constructor

    //Base class constructor is called first and then derived class constructor is called
    //Derived d;
    //d.setX(5);
    //d.setY(15);
    //cout << "X: " << d.getX() << endl;
    //cout << "Y: " << d.getY() << endl;
    return 0;
}
