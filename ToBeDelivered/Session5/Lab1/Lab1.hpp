/**
 * Lab 1
● Implement a class Integer that has a member variable
pointer to int (private) which points to a location in the
heap containing integer number.
● Implement the default constructor, parameterized
constructor, Copy constructor, move constructor and
the destructor.
● this class has two member functions:
Set_Value -> Change the value which the
pointer in this class points at
Get_Value -> return the value which the pointer
in this class points at
● Implement the Copy Assignment operator = to this
class similarly to the previous example in the slides.
and validate that it is working correctly.
*/
/**
 * Continuing on the previous class, Implement the move
Assignment operator =. add to this implementation a line that
print on the terminal indicating we are in the move assignment
operator
Then validate that is working properly by assigning a temp
value in object from this class and see what is printed on the
terminal

Continuing on the class we’ve implemented in this section,
add the insertion and extraction overloading operator to this
class and validate them
*/
/**
 * Lab 3
Continuing on the class we’ve implemented class Integer, add
these operators overloaded to it:
+ , - , * , ++ , -- , > , !=
Implement these functions and validate that they are working
correctly
*/
/**
 * Lab 4
 * Continuing on the class we’ve implemented in this section,
add the insertion and extraction overloading operator to this
class and validate them
*/
#include <iostream>

using namespace std;

// Define the class Integer
class Integer
{
private:
    int *m_pInt; // Pointer to an integer in the heap
public:
    // Default constructor
    Integer();   
    // Parameterized constructor
    Integer(int value);   
    // Copy constructor
    Integer(const Integer &obj);   
    // Move constructor
    Integer(Integer &&obj);   
    // Destructor
    ~Integer();   
    // Set the value of the integer
    void Set_Value(int value);   
    // Get the value of the integer
    int Get_Value() const;   
    // Copy assignment operator
    Integer &operator=(const Integer &obj);   
    // Move assignment operator
    Integer &operator=(Integer &&obj);   
    // Addition operator
    Integer operator+(const Integer &obj);   
    // Subtraction operator
    Integer operator-(const Integer &obj);   
    // Multiplication operator
    Integer operator*(const Integer &obj);   
    // Pre-increment operator
    Integer &operator++();
    // Post-increment operator
    Integer operator++(int);
    // Pre-decrement operator
    Integer &operator--();
    // Post-decrement operator
    Integer operator--(int);
    // Greater than operator
    bool operator>(const Integer &obj);
    // Not equal to operator
    bool operator!=(const Integer &obj);
    // Insertion operator
    friend ostream &operator<<(ostream &out, const Integer &obj);
    // Extraction operator
    friend istream &operator>>(istream &in, Integer &obj);
};