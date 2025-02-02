#include <iostream>
using namespace std;

bool present(int a[], int n, int e){
    //base case 
    if(n==0){
        return false;
    }

    //recursion
    if(a[0] == e){
        return true;
    }
    return present(a+1, n-1, e);
}

int main(){
    int a[5] = {1,2,4,5};

    cout<<present(a, 5, 3);

    return 0;
}