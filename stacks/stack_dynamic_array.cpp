//dynamic stack
//dynamic arrray --> vector 

//when array full create a new array with double the size and delete the previous array
//need to update push function

#include<iostream>
using namespace std;

class stack{
    int *arr;
    int capacity;
    int nextindex;
    public:
    stack(){
        capacity = 4;
        arr = new int[capacity];
        nextindex = 0;
    }
    stack(int cap){
        capacity = cap;              //size constraint 
        arr = new int[cap];
        nextindex = 0;
    }
    //size of stack
    int size(){
        return nextindex;
    }
    //isempty
    bool isempty(){
        if(nextindex ==0){
            return true;
        }
        else{
        return false;
        }

        //or
        //return nextindex == 0; //if 0==0 then tru
    }

    //push
    void push(int value){
        if(nextindex == capacity){    /////here's the change
            int *newarr = new int[2*capacity];
            for(int i=0; i<capacity; i++){
                newarr[i] = arr[i];
            }
            delete []arr;
            arr = newarr;
            capacity = 2*capacity;

        }
        arr[nextindex] = value;
        nextindex++;
    }

    //pop
    void pop(){
        if(isempty()){
            cout<<"stack empty";
            return;
        }
        nextindex--;
    }

    int top(){
        if(isempty()){
        cout<<"stack empty";
        return -1;
        }
        return arr[nextindex-1];
    }
};

int main(){
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);


    cout<<endl<<s.size()<<endl;

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.size()<<endl;
    cout<<s.isempty()<<endl;
    
    return 0;
}