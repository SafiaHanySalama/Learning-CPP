/**
 * Static member variables
 * this
 * Operator overloading
*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
    std::string name;
    std::string ID;
    
    public:
    //default constructor
    Person():name{"none"},ID{"none"}{
        std::cout << "Person::Person()" << std::endl;
    }
    //parameterized constructor
    /*Person(std::string source1,std::string source2):name{source1},ID{source2}{
        std::cout << "Person::Person(string,string)" << std::endl;
    }

     Person(std::string source1,std::string source2){
        std::cout << "Person::Person(string,string)" << std::endl;
        name = source1;
        ID = source2;
    } */
    Person(std::string name,std::string ID){
        std::cout << "Person::Person(string,string)" << std::endl;
        //this pointer used to differentiate between the class member and the local variable
        this->name = name;
        this->ID = ID;
    }
    //destructor
    ~Person(){
        std::cout << "Person::~Person()" << std::endl;
    }
    void display_person_info(void){
        std::cout << "Person name is " << name << std::endl;
        std::cout << "Person ID is " << ID << std::endl;
    }


};
int main(void)
{
    Person p1{"Tom","123"};
    p1.display_person_info();
    return 0;
}