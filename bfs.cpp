#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfsprint(vector<vector<int> > v, int sv){  //takes in input the graph and the starting vertex
    int n = v.size();
    vector<bool> visited(n,false);              //visited array, initially no node is visited 
    queue<int> q;
    q.push(sv);                                 //push first node in the queue
    visited[sv] = true;                         //update the value of sv in visited array
    
    while(!q.empty()){
        int cv = q.front();
        q.pop();
        cout<<cv<<"\t";
        for(int i=0;i<n;i++){
            if(v[cv][i] && visited[i] == false){     //check for the edge and then if it is already visited
                q.push(i);                           //if conditions true then the element will be pushed in node
                visited[i] = true;                   //status will be updated in the visited array which means already in queue
            }
        }
    }
}

int main(){
    int n,e;
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

    cout<<"BFS Traversal path: "<<endl;
    bfsprint(adj_matrix,0);

    return 0;
}