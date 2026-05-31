#include<iostream>
#include<cstring>
using namespace std;
    //if we copy only address of 0th index of the array ---->>> shallow copy
    //if we copy the entire array --->>>  deep copy
class student{
    int age;
    char *name;

    public:
        student(int age, char *name){          //address of name variable is passed
            this->age = age;     
            // this->name = name;  //shallow copy
             
            //deep copy....
            this->name = new char[strlen(name) + 1 ]; //+1 to copy the null character                      //deep copy
            strcpy(this-> name,name);
        }

        void display(){
            cout<<name<<" "<<age<<endl;
        }
};

int main(){
    
    char name[] = "abcd";
    student s1(20,name);
    s1.display();
    name[3] = 'e';
    student s2(30, name);
    s2.display();
    return 0;
}