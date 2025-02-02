#include <bits/stdc++.h>
using namespace std;

template <typename T> // write this line above every class
class node
{

    public:
    T data;
    node<T> *next;


    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class sstack
{
    node<T> *head;
    int size;

public:
    sstack()
    {
        head = NULL;
        size = 0;
    }
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        return size == 0;
    }
    void push(T ele)
    {
        node<T> *n = new node<T>(ele);
        n->next = head;
        head = n;
        size++;
    }
    void pop()
    {
        if (isempty())
        {
            cout << "stack empty";
            return;
        }
        node<T> *temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
    T top()
    {
        if (isempty())
        {
            cout << "stack empty";
            return 0;
        }
        return head->data; // if head == NULL segmentation error
    }
};

int main()
{
    sstack<char> s;

    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout << endl
         << s.getsize() << endl;

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.getsize() << endl;
    cout << s.isempty() << endl;

    return 0;
}