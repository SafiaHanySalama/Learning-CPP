/**
 * Write a C++ program to implement a class called Student that has
private member variables for name, class, roll number, and marks.
Include member functions to calculate the grade based on the marks
and display the student's information
*/

#include <iostream>
#include <string>

using namespace std;

class Student 
{
    std::string name;
    std::string class_name;
    int roll_number;
    int marks;
    public:
    //default constructor
    Student(){
        std::cout << "Student::Student()" << std::endl;
        name = "none";
        class_name = "none";
        roll_number = 0;
        marks = 0;
    }
    //parameterized constructor
    Student(std::string source1,std::string source2,int source3,int source4) : name{source1}
                                                                          ,class_name{source2}
                                                                          ,roll_number{source3}
                                                                          ,marks{source4}{
        std::cout << "Student::Student(string,string,int,int)" << std::endl;
    }
    //get the name of the student
    std::string get_name(void){
        return name;
    }
    //get the class of the student
    std::string get_class(void){
        return class_name;
    }
    //get the roll number of the student
    int get_roll_number(void){
        return roll_number;
    }
    //get the marks of the student
    int get_marks(void){
        return marks;
    }
    //set the name of the student
    void set_name(std::string source){
        name = source;
    }
    //set the class of the student
    void set_class(std::string source){
        class_name = source;
    }
    //set the roll number of the student
    void set_roll_number(int source){
        roll_number = source;
    }
    //set the marks of the student
    void set_marks(int source){
        marks = source;
    }
    //calculate the grade of the student
    char calculate_grade(void){
        if (marks >= 90){
            return 'A';
        } else if (marks >= 80){
            return 'B';
        } else if (marks >= 70){
            return 'C';
        } else if (marks >= 60){
            return 'D';
        } else {
            return 'F';
        }
    }
    //display the student's information
    void display_info(void){
        std::cout << "Student name is " << name << std::endl;
        std::cout << "Student class is " << class_name << std
        ::endl;
        std::cout << "Student roll number is " << roll_number << std::endl;
        std::cout << "Student marks is (0:100)" << marks << std::endl;
        std::cout << "Student grade is " << calculate_grade() << std::endl;
    }
};
int main(void)
{
    Student s1{"Safia","CS",1,90};
    s1.display_info();
    return 0;
}