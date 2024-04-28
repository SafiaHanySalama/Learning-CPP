#include <iostream>
#include <string>

using namespace std;

class Person
{
    //attributes 
    string name;
    int age;
    string ID;
    //Methods
    public:
        //Default Constructor 
        Person()
        {

        }
        void displayInfo(void)
        {
            std::cout << "name is " << name << std::endl;
            std::cout << "ID is " << ID << std::endl;
            std::cout << "Age: " << age << std::endl;
        }
        void displayOUTSIDE(void);

};
void Person::displayOUTSIDE(void)
{
   std::cout << "name is " << name << std::endl;
    std::cout << "ID is " << ID << std::endl;
    std::cout << "Age: " << age << std::endl; 
}
int main()
{
    Person Safia;
    //Acess Data
    //Dot operation for accessing the member 
        //Safia.name = "Safia";     //Error name is private accesifier 
        Safia.displayInfo();

    //Pointer to Object of this class
    Person* Obj = new Person;
        //Arrow Operator to access the member 
        Obj->displayInfo();
} 