
#include <iostream>
#include <string>

using namespace std;

class Person
{
    std::string name;
    std::string ID; 
    //friend function can access private members of the class attributes and methods
    friend void func_test();
    public:
    //static member variable shared by all objects of the class not specific to any object
    //Can't initialize in the class
     static int count;
    //default constructor
    Person():name{"none"},ID{"none"}{
        std::cout << "Person::Person()" << std::endl;
        count++;
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
        count++;
    }
    //destructor
    ~Person(){
        std::cout << "Person::~Person()" << std::endl;
    }
    void display_person_info(void) {
        std::cout << "Person name is " << name << std::endl;
        std::cout << "Person ID is " << ID << std::endl;
        /* @attention: Error, assignation in const function */
        //name = "Safia";
    }
    //static member function
    static void display_count(void){
        std::cout << "Count is " << count << std::endl;
    }


};

void func_test()
{
    static int test=0;
    test++;
    std::cout << "Test is " << test << std::endl;
}

//static member variable initialization
int Person::count = 0;
int main(void)
{
    Person::display_count();
    std::cout << "Count is " << Person::count << std::endl;
    Person p1{"Safia","123"};
    Person p2;
    Person p3;
    std::cout << "Count is " << Person::count << std::endl;

    //p1.display_person_info(); 
    /*Error Assignment(Compiler does not know if you will change member inside)
     of read-only member 'Person::name'*/
    //func_test();
    //func_test();
    //func_test();
    return 0;
}