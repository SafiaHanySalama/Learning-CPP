#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class myString
{
    char *str;
    friend myString operator+(const char *lhs, const myString &rhs);
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
    //Unary (Negative) operator overloading
    myString operator-(){
        //allocate memory for the new string
        char *buffer = new char[strlen(str)+1];
        //copy the string to the buffer string
        strcpy(buffer,str);
        //convert the string to lowercase
        for(int i=0;i<strlen(buffer);i++){
            buffer[i] = tolower(buffer[i]);
        }
        myString temp = myString(buffer);
        delete [] buffer;
        //return the new string
        return temp;
    }
    //Binary (+) operator overloading for concatenation
    //str1.operator+(str2)
    myString operator+(const myString &source){
        //allocate memory for the new string
        char *buffer = new char[strlen(str)+strlen(source.str)+1];
        //copy the string to the buffer string
        std::strcpy(buffer,str);
        //concatenate the source string to the buffer string
        std::strcat(buffer,source.str);
        myString temp = myString(buffer);
        delete [] buffer;
        //return the new string
        return temp;
    }
    //Compersion operator overloading == operator
    bool operator==(const myString &source){
        return (std::strcmp(str,source.str) == 0);
    }
    //Destructor
    ~myString(){
        delete [] str;
    }
    void display(){
        std::cout << str << std::endl;
    }
    
};
// Implementing outside the class
//Binary (+) operator overloading for concatenation 
//Glopbal function not related to any class
//We have to make it friend to the class to access the private member str
myString operator+(const char *lhs, const myString &rhs){
    //allocate memory for the new string
    char *buffer = new char[strlen(lhs)+strlen(rhs.str)+1];
    //copy the string to the buffer string
    std::strcpy(buffer,lhs);
    //concatenate the source string to the buffer string
    std::strcat(buffer,rhs.str);
    myString temp = myString(buffer);
    delete [] buffer;
    //return the new string
    return temp;
}
int main(void)
{
    myString str1{"SAFIA"};
    myString str2;
    str2 = -str1; //Convert the string to lowercase
    str1.display();
    str2.display();
    myString str3;
    str1 = " Hany";
    str3 = str2 + str1; //Concatenate the strings
    str3.display();
    if(str1 == str2){
        std::cout << "Strings are equal" << std::endl;
    }
    else{
        std::cout << "Strings are not equal" << std::endl;
    }
    return 0;
}