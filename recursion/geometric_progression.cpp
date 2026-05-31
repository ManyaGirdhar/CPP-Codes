#include <iostream>

using namespace std;

//1 + 1/2 + 1/2^2 + 1/2^3 + ..... 1/2^k

double gp(int k){
    if (k==0){
        return 1;
    }

    //recursion and calculation

    return gp(k-1) + 1.0/pow(2,k);
}

int main(){

    cout<<endl<<gp(0)<<endl;

    return 0;
}