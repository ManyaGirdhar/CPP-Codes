#include <iostream>

using namespace std;

void print1(int n){
    //base case
    if(n==0){
        return;
    }

    //recursive case

    print1(n-1);                    /////////ascending order

    cout<<n<<"\t";
   // return;   optional as function ends here

}

void print2(int n){
    //base case
    if(n==0){
        return;
    }                                  //////descending order

    cout<<n<<"\t";
    //recursive case

    print2(n-1);

    
    return;

}



int main(){
    print1(5);
    print2(5);
    
    return 0;
}