
#include <iostream>
#include <string>
#include <cstring>

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
    //Copy constructor
    Person(const Person &source){
        std::cout << "Person::Person(const Person &)" << std::endl;
        name = source.name;
        ID = source.ID;
    }
    void display_person_info(void) {
        std::cout << "Person name is " << name << std::endl;
        std::cout << "Person ID is " << ID << std::endl;
        /* @attention: Error, assignation in const function */
        //name = "Safia";
    }
    //Assignment operator overloading
    //To implement deep copy of the object, the return type should be reference to the object
    //chained equality like p1=p2=p3 can not be done if the return type is void because the return type of the first assignment will be void
    Person &operator=(const Person &source){
        std::cout << "Person::operator=(const Person &)" << std::endl;
        if(this == &source){
            return *this;
        }
        name = source.name;
        ID = source.ID;
        return *this;
    }
};
class myString
{
    char *str;
    public:
    //default constructor
    myString():str{nullptr}{
        str = new char('\0');
    }
    //parameterized constructor
    myString(char *src)
    {
        str = new char[strlen(src)+1];
        strcpy(str,src);
    }
    //Copy constructor
    myString(const myString &source){
        str = new char[strlen(source.str)+1];
        strcpy(str,source.str);
    }
    //move constructor
    myString(myString &&source){
        str = source.str;
        source.str = nullptr;
    }
    //Assignment operator overloading
    myString &operator=(const myString &source){
        //check for self assignment
        if(this == &source){
            return *this;
        }
        //delete the memory allocated for the str
        delete [] str;
        //allocate memory for the new str
        str = new char[strlen(source.str)+1];
        //copy the source string to the str
        strcpy(str,source.str);
        //return the reference to the object
        return *this;
    }
    //move assignment operator overloading
    myString &operator=(myString &&source){
        //check for self assignment
        if(this == &source){
            return *this;
        }
        //delete the memory allocated for the str
        delete [] str;
        //copy the source string to the str
        str = source.str;
        //set the source string to nullptr
        source.str = nullptr;
        //return the reference to the object
        return *this;
    }
    ~myString(){
        delete [] str;
    }
    
};
int main(void)
{
    Person p1{"Safia","1234"},p2;
    p2 = p1 ;
    p2.display_person_info();

    myString obj{"Hello"};
    myString str{obj}; //Copy constructor
    myString str3;
    str3 = str; //Assignment operator overloading
    //move constructor
    myString str4{std::move(str)};
    //move assignment operator overloading
    myString str5;
    str5 = std::move(str3);

    return 0;
}