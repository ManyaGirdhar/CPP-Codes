#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removedup(int *arr, int n){
    vector<int> output;
    unordered_map<int, bool> mymap;

    for(int i=0; i<n; i++){
        if(mymap.count(arr[i]) == 0){
            output.push_back(arr[i]);
            mymap[arr[i]] = true;
        }
    }
    return output;
}

int main(){
    int a[] = {1,5,3,4,5,2,1,2,3,1,6};
    vector<int> output = removedup(a, 11);
    for(int i = 0; i<output.size(); i++){
        cout<<output[i];
    }
}

