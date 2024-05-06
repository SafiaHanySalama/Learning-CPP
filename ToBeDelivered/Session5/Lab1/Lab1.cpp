#include "Lab1.hpp"
#include <iostream>
//Default Constructor
Integer::Integer()
{
    std::cout << "Default constructor: Integer() " << std::endl;
    m_pInt = new int(0);
}
//Parameterized Constructor
Integer::Integer(int value)
{
    std::cout << "Parameterized constructor: Integer(int value) " << std::endl;
    m_pInt = new int(value);
}
//Copy Constructor
Integer::Integer(const Integer &obj)
{
    std::cout << "Copy constructor: Integer(const Integer &obj) " << std::endl;
    m_pInt = new int(*obj.m_pInt);
}
//Move Constructor
Integer::Integer(Integer &&obj)
{
    std::cout << "Move constructor: Integer(Integer &&obj) " << std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}
//Destructor
Integer::~Integer()
{
    std::cout << "Destructor: ~Integer() " << std::endl;
    delete m_pInt;
}
//Copy Assignment Operator
Integer &Integer::operator=(const Integer &obj)
{
    if (this != &obj)
    {
        delete m_pInt;
        m_pInt = new int(*obj.m_pInt);
        std::cout << "Copy assignment operator: Integer &operator=(const Integer &obj) " << std::endl;
    }
    return *this;
}
//Move Assignment Operator
Integer &Integer::operator=(Integer &&obj)
{
    
    if (this != &obj)
    {
        delete m_pInt;
        m_pInt = obj.m_pInt;
        obj.m_pInt = nullptr;
        std::cout << "Move assignment operator: Integer &operator=(Integer &&obj) " << std::endl;
    }
    return *this;
}
//Overloading + operator
Integer Integer::operator+(const Integer &obj)
{
    std::cout << "Overloading + operator: Integer operator+(const Integer &obj) " << std::endl;
    Integer temp;
    *temp.m_pInt = *m_pInt + *obj.m_pInt;
    return temp;
}
//Overloading - operator
Integer Integer::operator-(const Integer &obj)
{
    std::cout << "Overloading - operator: Integer operator-(const Integer &obj) " << std::endl;
    Integer temp;
    *temp.m_pInt = *m_pInt - *obj.m_pInt;
    return temp;
}
//Overloading * operator
Integer Integer::operator*(const Integer &obj)
{
    std::cout << "Overloading * operator: Integer operator*(const Integer &obj) " << std::endl;
    Integer temp;
    *temp.m_pInt = *m_pInt * *obj.m_pInt;
    return temp;
}
//Overloading ++ operator for prefix
Integer &Integer::operator++()
{
    std::cout << "Overloading ++ operator for prefix: Integer &operator++() " << std::endl;
    ++(*m_pInt);
    return *this;
}
//Overloading ++ operator for postfix
// ++(int) is a dummy parameter to differentiate between prefix and postfix
Integer Integer::operator++(int)
{
    std::cout << "Overloading ++ operator for postfix: Integer operator++(int) " << std::endl;
    Integer temp(*this);
    ++(*m_pInt);
    return temp;
}
//Overloading -- operator for prefix
Integer &Integer::operator--()
{
    std::cout << "Overloading -- operator for prefix: Integer &operator--() " << std::endl;
    --(*m_pInt);
    return *this;
}
//Overloading -- operator for postfix
// --(int) is a dummy parameter to differentiate between prefix and postfix
Integer Integer::operator--(int)
{
    std::cout << "Overloading -- operator for postfix: Integer operator--(int) " << std::endl;
    Integer temp(*this);
    --(*m_pInt);
    return temp;
}
//Overloading > operator
bool Integer::operator>(const Integer &obj)
{
    std::cout << "Overloading > operator: bool operator>(const Integer &obj) " << std::endl;
    return *m_pInt > *obj.m_pInt;
}
//Overloading != operator
bool Integer::operator!=(const Integer &obj)
{
    std::cout << "Overloading != operator: bool operator!=(const Integer &obj) " << std::endl;
    return *m_pInt != *obj.m_pInt;
}
//Set Value
void Integer::Set_Value(int value)
{
    std::cout << "Set_Value() " << std::endl;
    *m_pInt = value;
}
int Integer::Get_Value() const
{
    std::cout << "Get_Value() " << std::endl;
    return *m_pInt;
}
//Insertion Operator
std::ostream &operator<<(std::ostream &out, const Integer &obj)
{
    out << "Insertion Operator" << *obj.m_pInt << std::endl;
    return out;
}
//Extraction Operator
std::istream &operator>>(std::istream &in, Integer &obj)
{
    std::cout << "Extraction Operator" << std::endl;
    in >> *obj.m_pInt; // Extracting the value from the user 
    return in;     
}
//Main Function
int main()
{
    Integer i1(10);
    Integer i2(20);
    Integer i3;
    cout << "The value of i1 is:" << endl;
    cout << i1.Get_Value() << endl;
    cout << "The value of i2 is:" << endl;
    cout << i2.Get_Value() << endl;
    i3 = i1 + i2;
    cout << "The value of i1+i2 is:" << endl;
    cout << i3.Get_Value() << endl;
    i3 = i1 - i2;
    cout << "The value of i1-i2 is:" << endl;
    cout << i3.Get_Value() << endl;
    i3 = i1 * i2;
    cout << "The value of i1*i2 is:" << endl;
    cout << i3.Get_Value() << endl;
    i3 = ++i1;
    cout << "The value of ++i1 is:" << endl;
    cout << i3.Get_Value() << endl;
    i3 = i1++;
    cout << "The value of i1++ is:" << endl;
    cout << i3.Get_Value() << endl;
    i3 = --i1;
    cout << "The value of --i1 is:" << endl;
    cout << i3.Get_Value() << endl;
    i3 = i1--;
    cout << "The value of i1-- is:" << endl;
    cout << i3.Get_Value() << endl;
    cout <<"The result of i1>i2? is:" << endl;
    cout << (i1 > i2) << endl;
    cout <<"The result of i1!=i2? is:" << endl;
    cout << (i1 != i2) << endl;
    cout << "Please enter a number to be added as object from class" << endl;
    cin >> i3;
    cout << "The number you have entered after being saved as object" << endl;
    cout << i3;
    return 0;
} 