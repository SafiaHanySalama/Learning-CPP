#include <iostream>
using namespace std;

class A{
    //Default access specifier is private
    int z;
    private:
        int y;
    protected:
        int x;
    public:
        int w;
};

class B: public A{
    public:
        void setX(int i){
            x = i; // x is protected member of class A and can be accessed in class B
        }
        /**
         * setY and setZ are not accessible in class B as they are private members of class A
        */
       void setW(int i){
           w = i; // w is public member of class A and can be accessed in class B
       }
};

//C inherits from A, but A is a private base class of C as default access specifier is private
class C: A{
    public:
        void setX(int i){
            x = i; // ERROR, x is protected member of class A and cannot be accessed in class C
        }
        /**
         * setY and setZ are not accessible in class C as they are private members of class A
        */
        void setW(int i){
            w = i; // w is public member of class A and can be accessed in class C
        }

};
//Protected inheritance
//Public and protected members of the base class become protected members of the derived class
//Private members of the base class are not accessible in the derived class
class D: protected A{
    public:
        void setX(int i){
            x = i; // x is protected member of class A and can be accessed in class D
        }
        /**
         * setY and setZ are not accessible in class D as they are private members of class A
        */
        void setW(int i){
            w = i; // w is public member of class A and can be accessed in class D
        }
};

int main(){
    //B inherits publicly from A so public and protected members of A are accessible in B 
    //but protected cannot be accessed in main
    B b;
    //b.x = 10; // ERROR x is protected member of class A and it protected in class B
    b.w = 40; // w is public member of class A and can be accessed in class B

    //C inherits privately from A so public and protected members of A are private in C
    C c;
    //c.x = 10; // ERROR x is protected member of class A and it is private in class C
    //c.y = 20; // ERROR y is private member of class A and it is private in class C
    //c.w = 40; // ERROR w is public member of class A and it is private in class C


    //D inherits protectedly from A so public and protected members of A are accessible in D
    D d;
    //d.x = 10; // ERROR x is protected member of class A and it protected in class D
    //d.y = 20; // ERROR y is private member of class A and it is not accessible in class D
    //d.w = 40; // ERROR w is public member of class A and protected in class D

    return 0;
}


