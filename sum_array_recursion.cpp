#include <iostream>
using namespace std;

int sum(int a[], int n){
    //base case
    if(n==0){
        return 0;
    }

    // //recursion and calculation
    // return sum(a+1, n-1) + a[0];

    return a[n-1] + sum(a, n-1);

    //or by using index
    //if(i==n)  //base case
    //return a[i] + sum(a, n, i+1);
}

int main(){

    int a[5] = {1,2,3,4,5};
    cout<<sum(a, 5);


    return 0;
}