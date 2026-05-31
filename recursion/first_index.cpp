#include<iostream>

using namespace std;
//first index of all the elements


int firstindex(int a[], int n, int x, int i){
    if(i == n){
        return -1;
    }

    if(a[i]==x){
        return i;
    }
    return firstindex(a, n, x, i+1);
}

int lastindex(int a[], int n, int x, int i){
    if(i == -1){
        return -3;
    }

    if(a[i] == x){
        return i;
    }

    return lastindex(a, n, x, i-1);
}

int main(){
    int a[] = {1,2,3,2};
    cout<<firstindex(a, 4, 2, 0)<<endl;
    cout<<lastindex(a, 4, 2, 3);                   //searching from back to forth
    return 0;
}