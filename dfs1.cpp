#include<iostream>
#include<vector>
using namespace std;


void dfsprint(vector<vector<int> > v, int sv, vector<bool> &visited){
    cout<<sv<<"  ";
    visited[sv] = true;
    int n = v.size();
    for(int i=0; i<n ; i++){
        if(v[sv][i]==1 && !visited[i]){
            dfsprint(v, i, visited);
        }
    }
}
int main(){
    int n,e;
    cout<<endl<<endl;
    cout<<"<------------------------------------------DFS PROGRAM--------------------------------------->"<<endl;
    cout<<"Enter the no. of vertices and edges: ";
    cin>>n>>e;

    vector<vector<int> > adj_matrix(n,vector<int>(n,0));

    cout<<"Enter the edges: "<<endl;
    for(int i = 0; i < e ; i++){
        
        int fv,lv;
cin>>fv>>lv;
        adj_matrix[fv][lv] = 1;         //undirected graph
        adj_matrix[lv][fv] = 1;
    }

    vector<bool> visited(n,false);

    cout<<"DFS Traversal path: "<<endl;
    dfsprint(adj_matrix,0,visited);

     return 0;
}