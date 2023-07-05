#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int a=1;
    for(auto x:v){
        if(x==a){
            a++;
        }
    }
    
    cout<<"The first non-existing positve number is: "<<a<<endl;
    return 0;
}