#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    int max_time=INT_MIN;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(max_time<b){
            max_time=b;
        }
        v[i].first=a;
        v[i].second=b;
    }
    sort(v.begin(),v.end());
    cout<<"Sorted pair"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    vector<int>time(max_time,-1);
    int total=0;
    for(int i=v.size()-1;i>=0;i--){
        for(int j=v[i].second-1;j>=0;j--){
            if(time[j] == -1 ){
                time[j]=v[i].first;
                total+=v[i].first;
                break;
            }
        }
    }
    int given_prof;
    cout<<"Enter profit: ";
    cin>>given_prof;

    int d;
    cout<<"Enter deadline of X :";
    cin>>d;

    cout<<"Time[0]: "<<time[0]<<endl;
    cout<<"Total: "<<total<<endl;
    int x=given_prof-total + time[0];
    cout<<"Value of X is: "<<x;    

    return 0;
}