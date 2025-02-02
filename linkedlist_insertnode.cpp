#include<iostream>

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

void insertinode(node *&head, node *n, int i){    //O(i)  == time complexity


    if(i<0){
        cout<<"-1";
        return;
    }

    if(i==0){

        n->next = head;
        head = n;
        return;
    }
    node *temp = head;  //using temporary varaible so that we can add the node at last index
    int c = 1;
    while(c<=i-1 && temp!=NULL){
        temp = temp->next;
        c++;
    }

        if(temp){
            n->next = temp->next;
            temp->next = n;
         }
         else{
            temp = n;
            temp->next = NULL;
            // n->next = head->next;
         }
}

int main(){

    node *head;
    node *n;
    int i, data;

    head = takeinput();
    printlist(head);
    
    cout<<"enter data: ";
    cin>>data;

    n = new node(data);
    
    cout<<"enter position: ";
    cin>>i;

    insertinode(head, n, i);
    printlist(head);
    return 0;
}