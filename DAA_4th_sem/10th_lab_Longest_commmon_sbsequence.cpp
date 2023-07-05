#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    string s1,s2;
    cout<<"\nEnter string 1: "<<endl;
    cin>>s1;
    cout<<"Enter string 2: "<<endl;
    cin>>s2;

    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>v(m+1,vector<int>(n+1,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(s2[i] == s1[j]){
                v[i+1][j+1]=1+v[i][j];
            }else{
                v[i+1][j+1] = max(v[i][j+1],v[i+1][j]);
            }
        }
    }
    // cout<<"\nPrinting the matrix DP: "<<endl;
    // for(auto a:v){
    //     for(auto x:a){
    //         cout<<x<<" ";
    //     }cout<<endl;
    // }
    cout<<"The length of longest Subsequence is :"<<v[m][n]<<endl;

    string subSequence;

    for(int i=m,j=n;i>0 && j>0;i--,j--){
        while(v[i][j]==v[i-1][j]){
            i--;
        }
        while(v[i][j]==v[i][j-1]){
            j--;
        }
        subSequence=s1[j-1]+subSequence;
    }

    cout<<"The longest Subsequence is: "<<subSequence<<endl<<endl;

    return 0;
}