#include<iostream>
#include<vector>

using namespace std;

void printArr(vector<int> arr)
{
    cout<<"\nPrinting Array: \n";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void quickSort(vector<int> &arr,int start,int end){
    if(start>=end){
        return;
    }
    int piv=arr[end];
    int x=start-1;
    for(int i=start;i<end;i++){
        if(arr[i]<piv){
            x++;
            swap(arr[i],arr[x]);
        }
    }
    swap(arr[end],arr[++x]);
    quickSort(arr,start,x-1);
    quickSort(arr,x+1,end);
}
int main(){
    
    vector<int> arr;
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;

    cout<<"Enter the elements:\n";
    int a;
    for (int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }printArr(arr);

    quickSort(arr,0,arr.size()-1);

    printArr(arr);
    return 0;
}