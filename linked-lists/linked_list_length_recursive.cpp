#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

void printlist(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

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



int length(node *head){
    if(head == NULL){
        return 0;
    }

    return 1 + length(head->next);
}
int main(){

    int data;
    node* head;
    node* n = NULL;

    head = takeinput();
    // node *temp = head;
    printlist(head);

    cout<<endl<<"the length of the list is: ";

    cout<<length(head);

    return 0;
}