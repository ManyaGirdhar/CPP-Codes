#include<bits/stdc++.h>
using namespace std;

template<typename T>  //template<typename T, typename V> for differnet values of x and y

class example{
    T x;
    T y;

    public:
    void setx(T x){
        this->x = x;
    }

    T getx(){
        return x;
    }

    void sety(T y){
        this->y = y;
    }

    T gety(){
        return y;
    }
};

int main(){
    example<int> p;
    p.setx(1);
    p.sety(2);

    cout<<endl<<p.getx()<<" "<<p.gety();

    example<double> p2;
    p2.setx(1.5);
    p2.sety(2.33);

    cout<<endl<<p2.getx()<<" "<<p2.gety();
    return 0;
}
