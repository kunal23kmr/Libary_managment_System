#include <iostream>
#include<vector>
using namespace std;

int m=0,n=0;

void DFS(int i,int j,vector<int> &mat){
    if(mat[(i*n)+j]==0) return; 
    if((i>=0) && (j>=0) && (i<m) && (j<n)){
        mat[(i*n)+j]=0;
        DFS(i-1,j,mat);
        DFS(i,j-1,mat);
        DFS(i+1,j,mat);
        DFS(i,j+1,mat);
        DFS(i-1,j-1,mat);
        DFS(i+1,j+1,mat);
        DFS(i-1,j+1,mat);
        DFS(i+1,j-1,mat);        
    }
}
int main()
{
    cout<<"\nEnter size of matrix: ";
    cin>>m>>n;

    vector<int>mat(n*m);

    int i=0,j=0;
    while(i<m){
        j=0;
        while(j<n){
            cin>>mat[(i*n)+j];
            j++;
        }
        i++;
    }
    i=0;
    int count=0;
    while(i<m){
        j=0;
        while(j<n){
            if(mat[(i*n)+j]!=0){
                DFS(i,j,mat);
                count++;
            }
            j++;
        }
        i++;
    }
    cout<<"\nNumber of I-land = "<<count<<"\n\n";

    return 0;
}