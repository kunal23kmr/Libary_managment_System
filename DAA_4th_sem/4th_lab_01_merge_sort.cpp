#include<iostream>
using namespace std;

void mergeSort(int *&arr,int s,int e){
    if(((e-s)<=0) ){ return; }

    int mid=(s/2 + e/2);
    int *larr= new int[mid+1];
    int *rarr=new int[e-mid];

    for(int i=0;i<mid+1;i++){
        larr[i]=arr[i+s];
    }
    for(int i=0;i<e-mid;i++){
        rarr[i]=arr[i+mid+1];
    }
    mergeSort(larr,s,mid);
    mergeSort(rarr,mid+1,e);

    int i=0,j=0;
    while((i<(mid+1)) && (j<(e-mid))){
        if(larr[i]>rarr[j]){
            arr[i+j]=larr[i];
            i++;
        }else{
            arr[i+j]=rarr[j];
            j++;
        }
    }
    while(i<mid+1){
        arr[i+j]=larr[i];
        i++;
    }
    while(j<e-mid){
        arr[i+j]=rarr[j++];
        j++;
    }
    delete larr,rarr;
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];

    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Calling mergeSort()."<<endl;
    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";

    return 0;
}