#include<iostream>
using namespace std;

class student{
    int age;

    public:
    int roll_no;

    student(int a, int r){
    age = a;
    roll_no = r;
    }

    student(){
    cout<<"constructor called";
    }
    void display(){
        cout<<age<<"\t";
        cout<<roll_no<<endl;
    }

    ~student(){
        cout<<"destructor called";
    }
};



int main(){

    student s1(10,100);
    // student s2(s1);    //copy constructor called for static object

    //for dynamic object

    student *s3 = new student(20,200);
    student s4(*s3);


    s1.display();
    // s2.display();

    student *s5 = new student(s1);
    s5->display();

    delete s5;

    return 0;
}