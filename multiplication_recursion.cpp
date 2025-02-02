#include <iostream>

using namespace std;

int mul(int m, int n){
   
    if(m == 0 || n == 0){
       return 0;
    }

    return m + mul(m, n-1);

}


int main(){
  
    cout<<mul(10, 10);
    
    return 0;
}