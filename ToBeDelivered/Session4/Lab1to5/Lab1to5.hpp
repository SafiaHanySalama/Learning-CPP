//Lab1
/**
 * Adding public methods that access private class attributes
Given the following Dog class in Dog.h add the following public getter
and setter methods that get and set each class attribute as follows:
get_name returns the name attribute of the dog
set_name sets the name attribute of the dog to the string that is
passed into the method.
get_age returns the age attribute of the dog
set_age sets the age attribute of the dog to the int passed into the
method.
*/
//Lab2
/**
 * Given the Dog class in
Dog.h, add a default
no-args constructor
that initializes the dog's
name to "None" and the
dog's age to zero.
Please add your code to
the Dog.h ﬁle.
*/
//Lab3
/**
 * Given the Dog class deﬁned
in Dog.h, add an overloaded
constructor that expect a
std::string and int as
parameters.
The constructor should allow
us to create Dog objects as
follows:
Dog ﬁdo {"Fido", 4};
Dog spot {"Spot", 5};
Please add your code to the
Dog.h ﬁle.
*/
//Lab4
/**
    Add a Copy Constructor to an Existing Class
    Given the Dog class deﬁned in Dog.h, add a Copy constructor.
    The copy constructor should copy the attributes from one
    object to another.
    Also, please display, "Copy Constructor" to cout in the body of
    your copy constructor. Do not follow the output statement
    with '\n' or endl
    The copy constructor should allow us to create Dog objects as
    follows.
    Dog spot {"Spot", 5}; // Overloaded constructor
    Dog twin {spot};
    // Copy constructor, twin will be a copy of spot
    Please add your code to the Dog.h ﬁle.
*/
//Lab5
/**
     * write a c++ code to count the the active objects that can be created
    Note :
    we can declare a counter that can be incremented when the object is
    created and decremented when the object is destroyed.
*/
#include <iostream>
#include <string>

using namespace std;

class Dog{
private:
    string name;
    int age;

public:
    static int count;
    //default constructor -> Lab2
    Dog(){
        std::cout << "Dog::Dog()" << std::endl;
        name = "None";
        age = 0;
        count++;
    }
    //Overloaded constructor -> Lab3 -> Parameterized constructor
    Dog(string source1,int source2) : name{source1}
                                    ,age{source2}{
        std::cout << "Dog::Dog(string,int)" << std::endl;
        count++;
    }
    //Copy constructor -> Lab4
    Dog(const Dog &source){
        name = source.name;
        age = source.age;
        cout << "Copy Constructor";
    }
    //getter and setter methods -> Lab1
    string get_name(void){
        return name;
    }
    void set_name(string source){
        name = source;
    }
    int get_age(void){
        return age;
    }
    void set_age(int source){
        age = source;
    }
    //Display
    
    //destructor
    ~Dog(){
        std::cout << "Dog::~Dog()" << std::endl;
        count--;
    }
};