#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL; // LL empty
    node *tail = NULL; // LL empty
    while (data != -1)
    {
        // node n(data); statically created data valid for one iteration only not stored as linkedlist one will be deletedd by the next data
        // dynamic allocation

        node *n = new node(data);

        // first node
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        // other nodes
        else
        {
            tail->next = n;
            tail = n;
        }
        cin >> data;
    }
    return head;
}

int search(node* head, int d){
    int c = 1;
    node * temp = head;
    while(temp != NULL){
        if(temp->data == d){
            return c;
        }
        temp = temp->next;
        c++;
    }
    return -1;
}



int main(){

    int data, d;
    node* head;
    node* n = NULL;

    head = takeinput();
    // node *temp = head;
    cout<<"enter data to be found: ";
    cin>>d;
    int s = search(head, d);
    if(s == -1){
        cout<<"data not found";
    }
    else
    cout<<"data is found at the position: "<<s;

    return 0;
}