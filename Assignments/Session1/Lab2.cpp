#include <iostream>
#include <string>

using namespace std;

class Person 
{
    // private members
    std::string name;
    std::string ID;
    int *ptr;
    // public members
    public:
        // Default Constructor
        Person() : name{"None"},ID {"None"}{
        std::cout << "Constructor has been called" << std::endl;
    }
    // parameterized constructor
    Person (std::string source, std::string source2) : name{source},ID{source2}{
        std::cout << "Person::Person(string,string)" << std::endl;
    }
    // Destructor
    ~Person(){
        std::cout <<  "Person::~Person()"   << std::endl;
    }
    void displayInfo(void);

};
void Person::displayInfo(void)
{
    std::cout << "name is " << name << std::endl;
    std::cout << "ID is " << ID << std::endl;
}
class Player {
    // Class members and methods go here
    std::string name;
    int health;
    double jh;
    public:
        Player():Player("none",0){
            std::cout << "Player::Player()" << std::endl;
        }
        Player(int source) : Player("none",source){
            std::cout << "player::player(int)" << std::endl;
        }
        Player (std::string source) : Player(source,0){
            std::cout << "Player::player(string)" << std::endl;
        }
        Player(std::string source1,int source2) : name{source1},health{source2}{
            std::cout << "player::player(string,int)" << std::endl;
        }
        ~Player(){
            std::cout << "Player::~Player()" << std::endl;
        }
        void displayInfo(void)
        {
            std::cout << "name is " << name << std::endl;
            std::cout << "health is " << health << std::endl;
        }
};
int main()
{
    Player Obj;
    Player Obj1(10);
    Player Obj2("Safia");
    Player Obj3("Safia",10);
    Obj.displayInfo();
    Obj1.displayInfo();
    Obj2.displayInfo();
    Obj3.displayInfo();
}
