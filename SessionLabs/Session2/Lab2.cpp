#include <iostream>
#include <string>

using namespace std;

class Dog
{
    std::string name;
    int age;
    int *ptr;
    public:
    //default constructor
    Dog(){
        std::cout << "Dog::Dog()" << std::endl;
        name = "none";
        age = 0;
    }
    //parameterized constructor
    Dog(std::string source1,int source2) : name{source1}
                                          ,age{source2}
                                          ,ptr{new int(0)}{
        std::cout << "Dog::Dog(string,int)" << std::endl;
    }
    //DEEP Copy constructor implementation
    Dog(const Dog &source){
        std::cout << "Dog::Dog(const Dog&)" << std::endl;
        name = source.name;
        age = source.age;
        ptr = new int;
        *ptr = *(source.ptr);
    }
    //get the name of the dog
    std::string get_name(void){
        return name;
    }
    //get the age of the dog
    int get_age(void){
        return age;
    }
    //set the name of the dog
    void set_name(std::string source){
        name = source;
    }
    //set the age of the dog
    void set_age(int source){
        age = source;
    }
    ~Dog(){
        std::cout << "Dog::~Dog()" << std::endl;
        delete ptr;
    }
};
int main(void)
{
    Dog d1{"Tommy",5};
    Dog d2 = d1;
    std::cout << "Dog name is " << d2.get_name() << std::endl;
    std::cout << "Dog age is " << d2.get_age() << std::endl;
    d2.set_name("Jimmy");
    d2.set_age(10);
    std::cout << "Dog name is " << d2.get_name() << std::endl;
    std::cout << "Dog age is " << d2.get_age() << std::endl;
    return 0;
}