#include<iostream>
#include<queue>
#define INT_MAX 9999999
#define INT_MIN -9999999
using namespace std;

template <typename T>
class btnode{
public:
    T data;
    btnode *left;
    btnode *right;

    btnode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~btnode(){
        delete left;      //delete null means do nothing
        delete right;
    }
};

void printtree(btnode<int>* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<": ";
    if(root->left){
        cout<<"L"<<root->left->data;
    }
    if(root->right){
        cout<<" R"<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
    
}

btnode<int> *inputrecursive(){
    int rootdata;
    cout<<"enter data: ";
    cin>>rootdata;

    if(rootdata == -1){
        return NULL;
    }

    btnode<int> *root = new btnode<int>(rootdata);

    btnode<int> *leftchild = inputrecursive();
    btnode<int> *rightchild = inputrecursive();

    root->left = leftchild;
    root->right = rightchild;           //first made left and right tree then the connection is made

    return root;
    
}

btnode<int> *inputlevelwise(){
    int rootdata, lchilddata, rchilddata;
    cout<<"enter data: ";
    cin>>rootdata;
    btnode<int> *root = new btnode<int> (rootdata);

    if(rootdata == -1){
        return NULL;
    }

    queue<btnode<int> *>q;
    q.push(root);

    while(!q.empty()){
        btnode<int> *f = q.front();
        q.pop();

        cout<<"enter data of left child of "<<f->data;
        cin>>lchilddata;

        if(lchilddata != -1){
            btnode<int> *lchild = new btnode<int> (lchilddata);
            q.push(lchild);
            f->left = lchild;
        }

        cout<<"enter data of right child of "<<f->data;
        cin>>rchilddata;

        if(rchilddata != -1){
            btnode<int> *rchild = new btnode<int> (rchilddata);
            q.push(rchild);
            f->right = rchild;
        }
    }
    return root;
}

void printlevelwise(btnode<int> *root){

    if(root==NULL){
        cout<<"no tree";
        return;
    }
    queue<btnode<int> *> q;
    q.push(root);

    while(!q.empty()){
        btnode<int> *f = q.front();
        q.pop();
        cout<<f->data;

    if(f->left){
        q.push(f->left);
    }
    if(f->left){
        q.push(f->right);
    }

    }
}

int countnodes(btnode<int> * root){
    if(root == NULL){   //edge case
        return 0;
    }

    int sum = 0;

    if(root->left){
        sum++;
    }
    if(root->right){
        sum++;
    }

    sum = 1+countnodes(root->left) + countnodes(root->right);
    return sum;
}

bool findnode(btnode<int> *root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return true;
    }

    // if(findnode(root->left, key) || findnode(root->right, key)){
    //     return true;
    // }

    return findnode(root->left, key) || findnode(root->right, key);
}

int minval(btnode<int> *root){
    if(root == NULL){
        return INT_MAX;          //if any of the subtree is NULL then max value is returned if 0 is returned then 0 will be assigned to minimum which will give wrong output
    }

    // int ans, minleft, minright;

    int  ans = root->data;
    int minleft = minval(root->left);
    int minright = minval(root->right);

    return min(ans, min(minleft, minright));
}

int maxval(btnode<int> *root){
    if(root == NULL){
        return INT_MIN;          //if any of the subtree is NULL then max value is returned if 0 is returned then 0 will be assigned to minimum which will give wrong output
    }

    // int ans, minleft, minright;

    int  ans = root->data;
    int maxleft = maxval(root->left);
    int minright = maxval(root->right);

    return max(ans, max(maxleft, minright));
}

int countleaf(btnode <int>* root){
    if(root == NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    return countleaf(root->left) + countleaf(root->right);
}

//building the tree from preorder and indorder traversal


int main(){

    btnode<int> *root; 
    // btnode<int> *n1 = new btnode<int>(2); 
    // btnode<int> *n2 = new btnode<int>(3); 

    // root->left = n1;
    // root->right = n2;

    

    // root = inputrecursive();
    root = inputlevelwise();
    // printtree(root);
    // printlevelwise(root);

    cout<<endl<<"no. of nodes in the tree are: ";
    cout<<countnodes(root);

    // cout<<endl<<findnode(root, 3);
    cout<<endl<<minval(root);

    cout<<endl<<"max value in tree: "<<maxval(root);
    cout<<endl<<"leaf nodes in tree: "<<countleaf(root);


    return 0;
}