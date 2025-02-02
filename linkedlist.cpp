#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
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
////////////////taking input from user

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

// input at head
node *takeinput2()
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
            n->next = head;
            head = n;
        }
        cin >> data;
    }
    return head;
}

int length(node *head)
{
    int c = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

void printinode(node *head, int i)
{ // more complex as we are using length function which increases complexity O(n) ultimately O(n+i) if n>>>> then very complex
    int c = 0;
    if (i == 0)
    {
        cout << endl
             << head->data;
    }
    if (i > length(head) - 1 || i < 0)
    {
        cout << "this index does not exist in the list";
    }
    else
    {
        while (c <= i)
        {
            head = head->next;
            c++;
        }

        cout << endl
             << head->data;
    }
}

void printinode2(node *head, int i)
{ // O(i)  --> faster   worst case --> O(n)

    if (i < 0)
    {
        cout << "-1";
        return;
    }

    int c = 1;

    while (c <= i && head != NULL)
    {
        head = head->next;
        c++;
    }
    if (head)
    {
        cout << endl
             << head->data;
    }
    else
    {
        cout << "-1";
    }
}

// to not change the position of head we can use temporary variable in place of head for traversal

int main()
{
    // static

    // node n1(1);

    // node *head = &n1;

    // node n2(2);
    // node n3(3);
    // node n4(4);
    // node n5(5);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // printlist(head);

    /////////////////dynamic
    // node *head2 = takeinput2();
    // printlist(head2);

    node *head = takeinput();
    printlist(head);

    int len = length(head);

    cout << endl
         << "length of the linkedlist is: " << len;

    // for printing ith node
    cout << "enter no of element to be printed";
    int i;
    cin >> i;
    printinode2(head, i);

    return 0;
}
