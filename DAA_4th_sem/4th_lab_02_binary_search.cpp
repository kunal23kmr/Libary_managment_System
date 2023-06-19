#include<iostream>
using namespace std;

int index=-1;

void bSearch(int *arr ,int a ,int s ,int e){
    if(index != -1 ){    return ;  }
    else if(s>e){ return ; }
    int mid=(s/2 + e/2);
    if(arr[mid]==a){
        index=mid;
        return;
    }else if(arr[mid]>a){
        bSearch(arr,a,s,mid);
    }else{
        bSearch(arr,a,mid+1,e);
    }    
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter target:"<<endl;
    int a;
    cin>>a;
    bSearch(arr,a,0,n-1);

    if(index != -1){
        cout<<"Element found at index: "<<index<<endl;
    }else{
        cout<<"Element not found.";
    }


    return 0;
}