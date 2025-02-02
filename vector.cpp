// #include<iostream>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(90);
    v.push_back(30);
    cout<<v.size()<<"\t"<<v.capacity()<<endl;


    v[3] = 40;
    v[4] = 90;
    v[5] = 50;
    cout<<endl<<v.size()<<"\t"<<v.capacity()<<endl;
    v[6] = 60;
    v.push_back(60);
    cout<<endl<<v.size()<<"\t"<<v.capacity()<<endl;

    sort(v.begin(), v.end());

    cout<<v[0]<<endl;  
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;      
    cout<<v[3]<<endl;  
    cout<<v[4]<<endl; 
    cout<<v[5]<<endl;

    //alternate of [] is at()

    cout<<"use of at() : "<<endl;
//only 4 elements in vector entered by push_back() so after 3rd index no element printed 
//at() checks the index validity    

    cout<<v.at(3)<<endl;
    // cout<<v.at(5)<<endl;

    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }


    




    return 0;
}