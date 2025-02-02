#include <iostream>

using namespace std;

int pow(int x, int n){

    //base case
    if (n==0){
        return 1;
    }
    //recursive case and calculation like smalloutput = pow(x, n-1)
    //then in next step return x * smalloutput
   
    return x * pow(x, n-1);
}

int main(){

    cout<<pow(5,3);
    return 0;
}
