#include <iostream>
using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;

    BTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }

};


class Pair{

    public:

    BTNode<int>* head;
    BTNode<int>* tail;
};



class BST
{
    BTNode<int> *root;

    void printTree(BTNode<int> *root)
    {
        if (root == NULL)
        { /// base case
            return;
        }

        cout << root->data << ": ";
        if (root->left != NULL)
        {
            cout << "L" << root->left->data;
        }

        if (root->right != NULL)
        {
            cout << "R" << root->right->data;
        }
        cout << endl;

        printTree(root->left);
        printTree(root->right);
    }
    bool hasData(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }

        if (node->data > data)
        {
            return hasData(node->left, data);
        }
        else
        {
            return hasData(node->right, data);
        }
    }

    BTNode<int>* insert(BTNode<int>* node, int data){
        if(node == NULL){
            BTNode<int>* n = new BTNode<int>(data);
            return n;
        }
        if(data < node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;
    }

    BTNode<int>* deleteData(BTNode<int>* node, int data){
        if(node == NULL) return NULL;
        if(!hasData(node, data)){
            return node;
        }
        if(data > node->data){
            node->right = deleteData(node->right, data);
        }
        else if(data < node->data){
            node->left = deleteData(node->left,data);
        }
        
        else{         //node->data == data
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->right == NULL){
                BTNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if(node->left == NULL){
                BTNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else{
                BTNode<int>* minnode = node->right;
                while(minnode->left != NULL){     //moving towards extreme left of right tree
                    minnode = minnode->left;
                }
                int rightmin = minnode->data;

                node->data = rightmin;          //replace the node value
                node->right = deleteData(node->right, rightmin);
            }
        }
        return node;
        }


///////converting BST to sorted linked list
        Pair convertoLL(BTNode<int>* root){
            if(root == NULL){
                Pair ans;
                ans.head = NULL;
                ans.tail = NULL;
            }
            if(root->left == NULL && root->right == NULL){
                Pair p;
                p.head = root;
                p.tail = root;
                return p;
            }

            else if(root->left && root->right == NULL){
                Pair leftll = convertoLL(root->left);
                leftll.tail->right = root;
                Pair ans;
                ans.head = leftll.head;
                ans.tail = root;
                return ans;
            }
            else if(root->left == NULL && root->right){
                Pair rightll = convertoLL(root->right);
                root->right = rightll.head;
                Pair ans;
                ans.head = root;
                ans.tail = rightll.tail;
                return ans;
            }
            else{
                Pair leftll = convertoLL(root->left);
                Pair rightll = convertoLL(root->right);
                
                leftll.tail->right = root;
                root->right = rightll.head;

                Pair ans;
                ans.head = leftll.head;
                ans.tail = rightll.tail;
                return ans;
            }
        }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    void deleteData(int data)
    {
        root = deleteData(root, data);

    }
    void insert(int data)
    {
        root = insert(root, data);
    }
    bool hasData(int data)
    {
        return hasData(root, data);
    }
    void print()
    {
        printTree(root);
    }

    BTNode<int>* convertoLL(){
        Pair p = convertoLL(root);

        BTNode<int>* temp = p.head;
        while(temp != NULL){
        temp->left = NULL;                 //left pointers pointing to NULL
        temp = temp->right;
    }

        return p.head;
    }


};


int main()
{
    BST b;

    b.insert(4);
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(6);
    b.insert(5);
    b.insert(7);

    b.print();

    // int data;
    // cin>>data;
    // cout<<endl<<b.hasData(data);

    // b.deleteData(10);

    // cout<<endl;

    // b.print();

    // b.deleteData(100);

    // cout<<endl;

    // b.print();

    // b.deleteData(20);

    // cout<<endl;

    // b.print();

    cout<<endl;
    BTNode<int>* head = b.convertoLL();

    BTNode<int>* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->right;
    }


    return 0;
}