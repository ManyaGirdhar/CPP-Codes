#include<iostream>
using namespace std;


//////////////////////////////////dynamic queue
template <typename T>
class queue{
    T *arr;
    int front;
    int next;
    int size;
    int capacity;

    public:
    queue(){
        capacity = 5;
        arr = new T[capacity];
        front = -1;
        next = 0;
        size = 0;
    }
        queue(int cap){
        capacity = cap;
        arr = new T[capacity];
        front = -1;
        next = 0;
        size = 0;
    }

    int getsize(){
        return size;
    }

    bool isempty(){
        return size == 0;
    }

    T frontindex(){
        if(isempty()){
            cout<<"queue empty";
            return 0;
        }

        return arr[front];
    }

    void push(T element){
        if(size == capacity){
            T *newarr = new T[2*capacity];
            int j = 0;
            for(int i = front; i<capacity; i++){
                newarr[j] = arr[i];
                j++;
            }
            for(int i=0; i<front ; i++){
                newarr[j] = arr[i];
                j++;
            }
            front = 0;   //update all indices according to new array
            next = capacity;
            capacity = 2*capacity;
            delete []arr;
            arr = newarr;
        }
        arr[next] = element;
        next = (next + 1)%capacity;
        if(front == -1){
            front = 0;
        }
        size++;
    }

    void pop(){
        if(isempty()){
            cout<<"queue empty";
            return;
        }

        front = (front + 1)%capacity;
        size--;
    }
};

int main(){

    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<endl<<q.frontindex();
    cout<<q.getsize();




    return 0;
}