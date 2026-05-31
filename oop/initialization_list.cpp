#include<iostream>

using namespace std;


class student{
    public:
        int age;
        const int rollNumber;
        int &x;     //age refernce variable

        student(int r, int age) : rollNumber(r), age(age), x(this->age){

        }
};

int main(){
    student s1(100,10);
    s1.age = 10;
    // s1.rollNumber = 100;

    return 0;
}