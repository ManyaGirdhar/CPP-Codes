#include <bits/stdc++.h>

using namespace std;

bool sort(int a[], int n){
    //base case
    if(n==0 || n==1){
        return true;
    }

    if(a[0]>a[1]){
        return false;
    }

    return sort(a+1, n-1);

    //recursion

}

int main(){

    int a[5] = {1,8,3,4,5}; 

    cout<<sort(a, 5);

    return 0;
}
