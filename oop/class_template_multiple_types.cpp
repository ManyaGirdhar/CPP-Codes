#include<bits/stdc++.h>
using namespace std;

template<typename T, typename V>  //template<typename T, typename V> for differnet values of x and y

class example{
    T x;
    V y;

    public:
    void setx(T x){
        this->x = x;
    }

    T getx(){
        return x;
    }

    void sety(V y){
        this->y = y;
    }

    V gety(){
        return y;
    }
};

int main(){
    example<example<int, double>, char> p;
    // p.setx(1);
    p.sety('a');

    example<int, double> temp;

    temp.setx(10);
    temp.sety(20.00);

    p.setx(temp);

    cout<<p.getx().getx()<<" "<<p.getx().gety()<<" "<<p.gety();

    return 0;
}
