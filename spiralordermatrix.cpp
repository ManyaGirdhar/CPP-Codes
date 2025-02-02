#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;
class Solution{
    public:
        vector<int> spiralorder(vector<vector<int>> &matrix){
            
            int m = matrix.size();      //size of a row
            int n = matrix[0].size();   //size of column
            
            int sr= 0, er = m-1, sc = 0, ec = n-1;
            int count = 0;

            while(sr<=er && sc<=ec){
                for(int i=sc;i<=ec;i++){
                    ans.push_back(matrix[sr][i]);       //print the first row
                    count++;
                }
                sr++;
                if(count == m*n){
                    return ans;
                }

                for(int i=sr;i<=er;i++){
                    ans.push_back(matrix[i][ec]);     //last column
                    count++;
                }
                ec--;
                if(count==m*n){
                    return ans;
                }

                for(int i=ec;i>=sc;i--){
                    ans.push_back(matrix[er][i]);     //last last row
                    count++;
                }
                er--;
                if(count==m*n){
                    return ans;
                }

                for(int i=er;i>=sr;i--){
                    ans.push_back(matrix[sc][i]);     //1st column
                    count++;
                }
                sc++;
                if(count==m*n){
                    return ans;
                }
            }

            return ans;    
        }
};


int main(){
    Solution m1;
    int m,n;
    vector<vector <int>> matrix;
    
    cout<<"entr matrix: ";
    cin>>m>>n;

    matrix.resize(m, vector<int>(n, 0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
         }
    }

    ans = m1.spiralorder(matrix);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    
    

    return 0;
}