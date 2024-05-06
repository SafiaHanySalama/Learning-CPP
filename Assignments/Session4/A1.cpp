/**
 * Write a C++ program to implement a class called Date that has
private member variables for day, month, and year. Include member
functions to set and get these variables, as well as to validate if the
date is valid.
*/

#include <iostream>
#include <string>

using namespace std;

class Date
{
    int day;
    int month;
    int year;
    public:
    //default constructor
    Date(){
        std::cout << "Date::Date()" << std::endl;
        day = 0;
        month = 0;
        year = 0;
    }
    //parameterized constructor
    Date(int source1,int source2,int source3) : day{source1}
                                              ,month{source2}
                                              ,year{source3}{
        std::cout << "Date::Date(int,int,int)" << std::endl;
    }
    //get the day of the date
    int get_day(void){
        return day;
    }
    //get the month of the date
    int get_month(void){
        return month;
    }
    //get the year of the date
    int get_year(void){
        return year;
    }
    //set the day of the date
    void set_day(int source){
        day = source;
    }
    //set the month of the date
    void set_month(int source){
        month = source;
    }
    //set the year of the date
    void set_year(int source){
        year = source;
    }
    //validate the date
    bool validate_date(void){
        if (day < 1 || day > 31){
            return false;
        }
        if (month < 1 || month > 12){
            return false;
        }
        if (year < 1900 || year > 2021){
            return false;
        }
        return true;
    }
    ~Date(){
        std::cout << "Date::~Date()" << std::endl;
    }
};

int main(void)
{
    Date d1{1,1,2021};
    std::cout << "Day is " << d1.get_day() << std::endl;
    std::cout << "Month is " << d1.get_month() << std::endl;
    std::cout << "Year is " << d1.get_year() << std::endl;
    if (d1.validate_date()){
        std::cout << "Date is valid" << std::endl;
    }
    else{
        std::cout << "Date is invalid" << std::endl;
    }
    d1.set_day(32);
    d1.set_month(13);
    d1.set_year(2022);
    std::cout << "Day is " << d1.get_day() << std::endl;
    std::cout << "Month is " << d1.get_month() << std::endl;
    std::cout << "Year is " << d1.get_year() << std::endl;
    if (d1.validate_date()){
        std::cout << "Date is valid" << std::endl;
    }
    else{
        std::cout << "Date is invalid" << std::endl;
    }
    return 0;
}