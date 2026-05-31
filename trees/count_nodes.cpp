#include<iostream>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

template<typename T>
class treenode{
    public:
    T data;
    vector<treenode<T>*> child;

    treenode(T data){
        this->data = data;
    }
};

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

void printatlevelk(treenode<int> *root, int k){
    if(root == NULL){
        return;
    }
    if(k==0){
        cout<<root->data;
        return;
    }
    for(int i=0; i<root->child.size(); i++){
        printatlevelk(root->child[i], k-1);
    }
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


int countnodes(treenode<int> * root){
    if(root == NULL){   //edge case
        return 0;
    }

    int n = 1;
    // int sum = 0;
    for(int i=0 ; i<root->child.size(); i++){
        n = n + countnodes(root->child[i]);
    }
    return n;
}


int countnodes2(treenode<int> * root){
    if(root == NULL){   //edge case
        return 0;
    }

    int n = 1;
    int sum = 0;
    for(int i=0 ; i<root->child.size(); i++){
        sum = sum + countnodes(root->child[i]);
    }

    sum = n+sum;
    return sum;
}

int height(treenode<int> * root){
        if(root == NULL){   //edge case
        return 0;
    }

    int mx = 0;
    for(int i=0 ; i<root->child.size(); i++){
        // int childheight = height(root->child[i]);
        // if(childheight > max){
        //     max = childheight;
        // }
        mx = max(mx, height(root->child[i]));
    }

    return mx+1;
}

int countleaf(treenode<int>* root) {
    // Base case: If the root is null, return 0
    if (root == NULL) {
        return 0;
    }

    // If the current node is a leaf node
    if (root->child.size() == 0) {
        cout << root->data << " ";
        return 1;
    }

    // Initialize leaf count
    int c = 0;

    // Recur for all children
    for (int i = 0; i < root->child.size(); i++) {
        c += countleaf(root->child[i]);
    }

    return c;
}

    

int main(){

    treenode<int> *root = takeinputlevelwise();
    // printatlevelk(root, 2);
    // cout<<endl<<countnodes2(root);
    // int h = height(root);

    int c = countleaf(root);
    cout<<"no. of leaf nodes in the tree are: "<<c;

    return 0;
}