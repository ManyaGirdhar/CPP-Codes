//Recursion

#include <iostream>
using namespace std;

int fib(int n){
   if(n==0){
    return 0;
   }

   if(n==1){
    return 1;
   }

   int f1 = fib(n-1);
    int f2 = fib(n-2);
   return  f1 + f2;
}

int main(){

    cout<<fib(7);
    return 0;
}