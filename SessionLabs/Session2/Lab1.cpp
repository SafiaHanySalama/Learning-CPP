#include <iostream>
#include <string>

using namespace std;

class Player {
    // Class members and methods go here
    std::string name;
    int health;
    int *ptr;
    public:
// default constructor , delgate to another constructor
    Player():Player("none",0,0){
        std::cout << "Player::Player()" << std::endl;
    }
    Player(int source) : Player("none",source,0){
        std::cout << "Player::Player(int)" << std::endl;
    }
    Player (std::string source) : Player(source,0,0){
        std::cout << "Player::Player(string)" << std::endl;
    }
    // parameterized constructor
    /* Ptr is a pointer to an integer and it is dynamically allocated, 
    in case of default copy constructor it will be shallow copy and it will cause a problem as it will point to the same memory location
    so we need to define a copy constructor to make a deep copy of the pointer
    */
    Player(std::string source1,int source2,int source3) : name{source1}
                                                        ,health{source2}
                                                        ,ptr{new int(source3)}{
        std::cout << "Player::Player(string,int)" << std::endl;
    }
    // user defined copy constructor 
    Player(const Player &source){
        std::cout << "Player::Player(const Player&)" << std::endl;
        name = source.name;
        health= source.health;
        ptr = new int;
        *ptr = *(source.ptr);
    }
    // display info
    void display_info(void)
    {
        std::cout << "Player name is " << name << std::endl;
        std::cout << "Player health is " << health << std::endl;
        std::cout << "Player pointer is " << *ptr << std::endl;
        // Print the memory address of the pointer
        std::cout << "Player pointer memory address is " << ptr << std::endl;
        
    }
    // Destructor
    ~Player(){
        std::cout << "Player::~Player()" << std::endl;
        delete ptr;
    }
};

int main()
{
    //Parameterized constructor 
    Player p1{"Safia",100,90};
    Player p2=p1;       //This will call the copy constructor
    p1.display_info();  
    p2.display_info(); //Address of the pointer will be different in both objects
}