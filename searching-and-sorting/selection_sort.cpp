#include<iostream>
#include<vector>
#include<climits>

using namespace std;


void selection(vector<int> &v, int n){       //passed address of the vector so that changes can be reflected to main function too!
    cout<<"selection process start"<<endl;
     for(int i=0; i<n-1; i++){
        int smallest = i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[smallest]){
                smallest = j;
            }
        }
                swap(v[i], v[smallest]);
    }
}


int main(){
    
    int n, element;
    vector<int> v;

    cout<<"enter no. of elements in array: ";

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>element;
        v.push_back(element);
    }

    //selection sort

    selection(v, n);

    for(int i=0; i<n; i++){
        cout<<v[i];
    }


    return 0;
}