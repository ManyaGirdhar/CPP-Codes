#include<iostream>
#include<vector>
using namespace std;

//O(n)  time complexity/n-steps



int findkey(int n, vector<int> &v, int key){
    for(int i=0; i<n; i++){
        if(v[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    
        int n,key,element,index;
        vector<int> v;

        cout<<"enter no. of elements: "<<endl;
        cin>>n;

        cout<<"enter elemts in array: "<<endl;
        for(int i = 0; i<n; i++){
            cin>>element;
            v.push_back(element);
        }

        cout<<"enter key to be found in array: "<<endl;
        cin>>key;

        index = findkey(n,v,key);
        
        if(index==-1){
            cout<<"no key found";
        }
        else{
            cout<<"the given key is present at following index: "<<endl<<index;;
        }


    return 0;
}