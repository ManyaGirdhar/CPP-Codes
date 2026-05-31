#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class treenode{
    public:
    T data;
    vector<treenode<T>*> child;

    treenode(T data){
        this->data = data;
    }

    //deleting using destructor
    ~treenode(){
        for(int i=0; i<child.size(); i++){
            delete child[i];
        }
    }
};

void printtree(treenode<int> *root){
    if(root == NULL){          //edge case
        return;
    }

    cout<<root->data<<": ";

    for(int i=0; i<root->child.size(); i++){        //leaf node acting as base case as size become zero control will not enter loop
        cout<<root->child[i]->data<<" ,";
    }
    cout<<endl;

    for(int i=0; i<root->child.size(); i++){
        printtree(root->child[i]);
    }

}

void printlevelwise(treenode<int> *root){
    queue<treenode<int> *> q;
    q.push(root);

    while(!q.empty()){
        treenode<int> *f = q.front();
        q.pop();

        cout<<f->data<<": ";

        for(int i=0; i<f->child.size(); i++){
            cout<<f->child[i]->data<<", ";
            q.push(f->child[i]);
        }
        cout<<endl;
    }

}

treenode<int> * takeinput(){
    int rootdata;
    cout<<"enter data: "<<endl;
    cin>>rootdata;

    treenode<int>* root = new treenode<int>(rootdata);
    
    //for no. of children

    int n;
    cout<<"enter no. of chiildren of "<<rootdata<<": ";
    cin>>n;

    for(int i=0; i<n; i++){
        treenode<int>* chld = takeinput();
        root->child.push_back(chld);
    }
    return root;
}

treenode<int> * takeinputlevelwise(){
    int rootdata;
    cout<<"enter root data: ";
    cin>>rootdata;
    treenode<int> *root = new treenode<int> (rootdata);

    queue<treenode<int> *> q;
    q.push(root);


    while(!q.empty()){
        treenode<int> *f = q.front();
        q.pop();

        int n;
        cout<<"enter no. of children of "<<f->data;
        cin>>n;

        for(int i=0; i<n; i++){
            int childdata;
            cout<<"enter childdata of " << i<< "th child: ";
            cin>>childdata;

            treenode<int> *chld = new treenode<int> (childdata);
            q.push(chld);
            f->child.push_back(chld);
        }
    }
    return root;
}

void preorder(treenode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0; i<root->child.size(); i++){
        preorder(root->child[i]);
    }
}

void postorder(treenode<int> *root){
    if(root == NULL){
        return;
    }
    for(int i=0; i<root->child.size(); i++){
        postorder(root->child[i]);
    }
    cout<<root->data<<" ";
}


//delete by post order traversal
void deletetree(treenode<int> *root){
    if(root == NULL){
        return;
    }
    for(int i=0; i<root->child.size(); i++){
        deletetree(root->child[i]);
    }
    delete root;
    cout<<"deleted";
}


int main(){
    // treenode<int> *root = new treenode<int>(1);
    // treenode<int> *n1 = new treenode<int>(2);
    // treenode<int> *n2 = new treenode<int>(3);
    
    // root->child.push_back(n1);
    // root->child.push_back(n2);

    //take input
    treenode<int> *root = takeinputlevelwise();
    
    //print recursive

    printlevelwise(root);

    preorder(root);

    cout<<endl;
    postorder(root);

    deletetree(root);

    //using destructor 
    delete root;

    return 0;
}