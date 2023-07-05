#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s=0, end=n-1;
    while(s<=end){
        swap(arr[s],arr[end]);
        s++,end--;
    }cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}