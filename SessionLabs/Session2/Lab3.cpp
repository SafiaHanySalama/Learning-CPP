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
    Player(std::string source1,int source2,int source3) : name{source1}
                                                        ,health{source2}
                                                        ,ptr{new int(source3)}{
        std::cout << "Player::Player(string,int)" << std::endl;
    }
    //Move constructor
    /* Move constructor is a  constructor that takes an rvalue reference to an object of the same class as its first parameter.
    It is used to move an object rather than copy it. It is called when an object is initialized from an rvalue.
    */
    Player(Player &&source){
        std::cout << "Player::Player(Player&&)" << std::endl;
        source.name = name;
        source.health = health;
        source.ptr = nullptr;
    }
    //Display info
    void display_info(void)
    {
        std::cout << "Player name is " << name << std::endl;
        std::cout << "Player health is " << health << std::endl;
        if (ptr) {
        std::cout << "Player pointer is " << *ptr << std::endl;
        } else {
        std::cout << "Player pointer is nullptr" << std::endl;
        }
        // Print the memory address of the pointer
        //std::cout << "Player pointer memory address is " << ptr << std::endl;
        
    }

};

int main()
{
    //Parameterized constructor 
    Player p1{"Safia",100,90};
    p1.display_info();
    //Move constructor
    Player p2 = std::move(p1);
    p1.display_info();
    p2.display_info();
    return 0;
}
