#include<iostream>

using namespace std;

template <typename T>
class node{
    public:
    int data;
    node* next;

    node(T data){
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class queue{
    node<T> *head;
    node<T> *tail;
    int size;

    public:
    queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getsize(){
        return size;
    }
    
    bool isempty(){
        return size == 0;
    }

    T front(){
        if(isempty()){
            cout<<"queue empty";
            return 0;
        }
        return head->data;
    }
    void push(T data){
        node<T> *n = new node<T>(data);

        if(size == 0){
            head = n;
            tail = n;
        }
        else{
            tail -> next = n;
            tail = n;
        }
        size++;
    }

    void pop(){
        if(isempty()){
            cout<<"queue is empty";
            return;
        }

        node<T> *temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
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
    
    cout<<endl<<q.front();
    cout<<q.getsize();
    while(!q.isempty()){
        cout<<q.front();
        q.pop();
    }
    return 0;
}