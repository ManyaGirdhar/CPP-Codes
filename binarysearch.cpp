#include<iostream>
#include<algorithm>

using namespace std;

int binarysearch(int a[], int n, int key){
    int s = 0, e = n-1;

    while(s <= e){
        int mid = s + (e - s)/2;

        if(a[mid] == key){
            return mid;
        }
        else if(a[mid] < key)
        {
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        }

    return -1;

}



int main(){
    int n, key;

    cout<<"enter the no. of elements in your array: ";
    cin>>n;

    int a[n];

    cout<<"enter array: ";
    for(int i=0; i< n; i++){
        cin>>a[i];
    }


    sort(a, a+n);

    cout<<"enter key to be found: ";
    cin>>key;
    
    int pos = binarysearch(a, n, key);

    if(pos == -1){
        cout<<"key not found!";
    }
    else{
        cout<<"your element is at position: "<<pos+1;
    }

    


    
    return 0;
}