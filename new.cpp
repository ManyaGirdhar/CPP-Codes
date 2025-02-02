#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, pos;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    // sort(arr, arr + n);
    // cin>>pos;
    // // for(int i = n; i>pos; i--){
    // //     cout<<arr[pos];
    // // }
    // arr[n-pos];

    // return 0;

    int high = arr[0];
    int indexh;
    for(int i = 0; i<n; i++){
        if(high < arr[i]){
            high = arr[i];
            indexh = i;
        }
    }

    
    if(high = arr[0]){
        int shigh = arr[1];
    }
    else{
        int shigh = arr[0];
    }
    
    int indexsh;
    for(int i = 0; i<n; i++){
        if(i == indexh){
            continue;
        }
        if(shigh < arr[i] && high > shigh){
            shigh = arr[i];
            indexsh = i;
        }      
        
    }
        cout<<shigh;
    return 0;

}