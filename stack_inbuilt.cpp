#include<iostream>
#include<stack>
using namespace std;

//inbuilt stack is implemented via templates

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.empty();
    return 0;
}