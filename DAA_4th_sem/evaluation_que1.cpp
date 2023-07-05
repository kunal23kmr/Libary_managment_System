#include<iostream>
#include<vector>
using namespace std;

int findMax(bool a,int i,vector<int> &h,vector<int> dp){
    if(i>=h.size()){
        return 0;
    }
    int l,r;
    if(a==true){
        l= findMax(true,i+2,h,dp);
        r= findMax(false,i+2,h,dp);
        dp[i]= h[i] + max(l,r);
    }else{
        l= findMax(true,i+1,h,dp);
        r= findMax(false,i+1,h,dp);
        dp[i]= max(l,r);
    }    
        
    return dp[i];
}

int main(){
    int n;
    cout<<"Enter number of houses: ";
    cin>>n;
    vector<int>h(n);
    vector<int>dp(n,-1);
    cout<<"Enter money in houses: "<<endl;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int l= findMax(true,0,h,dp);
    int r= findMax(false,0,h,dp);
    dp[0]=max(l,r);
    int maxi=0;
    for(auto a:dp){
        if(a>maxi){
            maxi=a;
        }
    }
    cout<< maxi;
    return 0;
}