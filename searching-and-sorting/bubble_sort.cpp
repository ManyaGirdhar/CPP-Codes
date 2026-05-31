#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bubblesort(int n, vector <int> &v){
    for(int i=1; i<=n-1; i++){           //no. of loops
        for(int j=0; j<=n-2; j++){       //for comparing j and j+1 element
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }   

    for(int i=0; i<n; i++){
        cout<<v[i];
    }  

}


void optimisedbubblesort(int n, vector<int> &v){
    for(int i=1; i<=n-1; i++){   

        int flag = 0;
               
        for(int j=0; j<=n-i; j++){       //for comparing j and j+1 element
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                flag = 1;
            }
        }

        if (flag == 0){
            cout<<endl
            <<"array is already sorted!! so now the complexity is O(n)";
            return;         //array is already sorted come out of the loop and O(n) complexity will be achieved!
        }
    }   

    for(int i=0; i<n; i++){
        cout<<v[i];
    } 
}


int main(){

    int n,a;
    cout<<"enter no. of elements: ";
    cin>>n;

    vector <int> v;

    for(int i=0; i<n; i++){
        cin>>a;
        v.push_back(a);
    } 

    // bubblesort(n,v);
    // optimisedbubblesort(n,v);

    cout<<"using inbuilt sort function: ";
    sort(v.begin(),v.end());
    
     for(int i=0; i<n; i++){
        cout<<v[i];
    } 

    
    return 0;
}