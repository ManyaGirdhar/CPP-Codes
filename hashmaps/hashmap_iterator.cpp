#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> mymap;

    mymap["abc"] = 1;
    mymap["abc1"] = 2;
    mymap["abc2"] = 3;
    mymap["abc3"] = 4;
    mymap["abc4"] = 5;
    mymap["abc5"] = 6;
   
    for(unordered_map<string, int>::iterator it = mymap.begin(); it != mymap.end(); it++){
        cout<<"for key "<<it->first<<", corresponding value is "<<it->second<<endl;
    }

    map<string, int> mymap2;   //sorted according to keys

    mymap2["abc"] = 1;
    mymap2["abc3"] = 2;
    mymap2["abc2"] = 3;
    mymap2["abc1"] = 4;
    mymap2["abc4"] = 5;
    mymap2["abc5"] = 6;
   
    for(map<string, int>::iterator it = mymap2.begin(); it != mymap2.end(); it++){
        cout<<"for key "<<it->first<<", corresponding value is "<<it->second<<endl;
    }

    vector<int> v;
    v.push_back(11);
    v.push_back(2);
    v.push_back(3);
    v.push_back(47);
    v.push_back(5);

    for(auto it = v.begin(); it != v.end(); it++){
        cout<<*it<<endl;
    }


auto it = mymap.find("abc");
mymap.erase(it);

//find fucntion takes key and returns iterator
    if(mymap.find("abc") == mymap.end()){
        cout<<endl<<"not present";
    }
    else{
        cout<<endl<<"present";
    }

    

    return 0;
}