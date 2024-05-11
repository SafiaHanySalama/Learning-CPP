/**
 * 
 * Implement a class Person that has member variables:
name, ID, age, gender and country.
The class has member functions to set all these variables
and a function to display these data
From this class we want to create class Student which
will inherit public from class Person and this class will
have member variables course and fees
Class Student have member functions to set the course
and fees variables and any other required variables and
display function
*/
#include <iostream>
#include <string>
using namespace std;

class Person{
    string name;
    int ID;
    int age;
    string gender;
    string country;
    public:
        void setName(string n){
            name = n;
        }
        void setID(int i){
            ID = i;
        }
        void setAge(int a){
            age = a;
        }
        void setGender(string g){
            gender = g;
        }
        void setCountry(string c){
            country = c;
        }
        void display(){
            cout << "Name: " << name << endl;
            cout << "ID: " << ID << endl;
            cout << "Age: " << age << endl;
            cout << "Gender: "<< gender << endl;
            cout << "Country: " << country << endl;
        }
};
class Student: public Person{
    string course;
    int fees;
    public:
        void setCourse(string c){
            course = c;
        }
        void setFees(int f){
            fees = f;
        }
        void display(){
            Person::display();
            cout << "Course: " << course << endl;
            cout << "Fees: " << fees << endl;
        }
};
int main(){
    Student s;
    s.setName("Safia");
    s.setID(1234);
    s.setAge(20);
    s.setGender("female");
    s.setCountry("Om eldonia");
    s.setCourse("C++");
    s.setFees(1000);
    s.display();
    return 0;
}