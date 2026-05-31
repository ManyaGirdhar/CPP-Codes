#include<iostream>
using namespace std;

class Fraction{
    private:
        int num;
        int den;

    public:
       //parametrized constructor as num, and den should not contain garbage value
        Fraction(int num, int den){
            this->num = num;
            this->den = den;
        }
        
        void add(Fraction const &f2){  //to avoid copy, use reference and (const) so that we cannot change the properties of f2
            int lcm = den * f2.den;
            int x = lcm/den;
            int y = lcm/f2.den;
            num = x * num + y * f2.num;
            den = lcm;
            
            this->num = num;
            this->den = den;
            
            simplify();
            
        }

         void mul(Fraction const &f2){
            num = num *f2.num;
            den *= f2.den;
            simplify();

        }

        void simplify(){
            int gcd = 1;
            int j = min(num,den);
            for(int i = 1; i<=j; i++){
                if(num%i==0 && den%i==0){
                    gcd = i;
                }
            }

            num = num/gcd;
            den = den/gcd;
        }

        //inbuilt function for gcd
        // c = __gcd(a,b);

        //constant function

        void print(){
            cout<<num<<"/"<<den;
        }

        int getNumerator(){
            return num;
        }

        int getDenominator(){
            return den;
        }

         int setNumerator(int n){
            num = n;
        }

        int setDenominator(int d){
            den = d;
        }
};


int main(){
    Fraction f1(4,2);
    Fraction f2(4,2);
    f1.add(f2);

    f1.print();
    cout<<endl;
    f1.mul(f2);
    f1.print();
    cout<<endl;
    f2.print();

    //f3.setNumerator(10);   we cannot use this function because
 
    return 0;
}