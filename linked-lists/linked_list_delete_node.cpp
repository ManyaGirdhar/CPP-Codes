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

node *delinode(node *head, int i){
    if(i<0){
        return head;
    }
    if(i==0 && head){
        return head->next;    //if head=NULL, then NULL->next will give run time error
    }
    
    node* curr = head;
    int c=1;
    while(c<=i-1 && curr){
        curr = curr->next;
        c++;
    }
    if(curr && curr->next){
        curr->next = curr->next->next;
        return head;
    }
    return head;
}


//deleting without memory leak
node *delinode2(node* head, int i){             //time complexity: O(i) worst case: O(n)
    if(i<0){
        return head;
    }

    if(i==0 && head){
        node *newhead = head->next; //isolate the node
        head->next = NULL;
        delete head;                //delete node
        return newhead;
    }

    node *curr = head;
    int c = 1;
    while(c<=i-1 && head){
        curr = curr->next;
        c++;
    }

    if(curr && curr->next){
        node *temp = curr->next;
        curr->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head;
    }

    return head;


}



int main(){
    node *head;
    node *n;
    int i, data;

    head = takeinput();
    printlist(head);
    
    cout<<"enter position of element to be deleted: ";
    cin>>i;

    head = delinode2(head, i);
    printlist(head);

    return 0;
}