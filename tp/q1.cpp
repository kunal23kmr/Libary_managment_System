// /*#inlcude<map>

// int fun(int *arr,int N){
//     map,int,int>m;
//     for(int i=0;i<N;i++){
//         m[ar[i]]++;
//     }
//     int ans = 0;
//     for(auto it:m){
//         if(it.second == 1){
//             ans = 1;
//         }else{
//             ans = 0;
//         }
//     }
//     return ans;
// }*/

// bool check(int N,int x,vector<int>&A){
//     A[0]+=x;
//     for(int i=1;i<n;i++){
//         if(A[i]>=A[i-1]){
//             A[i] = A[i]-x;
//         }
//     }
//     for(int i=1;i<N;i++){
//         if(A[i]>=A[i-1]){
//             return false;
//         }
//     }
//     return true;
// }

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int main()
{
    cout << "Current process Id : " << getpid() << endl;
    pid_t childProcessId = fork();
    if (childProcessId < 0)
    {
        cout << "Failed to Create a new Process" << endl;
    }
    else if (childProcessId == 0)
    {
        cout << "Child Process Id : " << getpid() << " Its parent ID :" << getppid() << endl;
        cout << "Child Process exits" << endl;
    }
    else if (childProcessId > 0)
    {
        cout << "Parent Process Id : " << getpid() << " Its Child Process ID : " << childProcessId << endl;
        sleep(30);
        cout << "Parent Process exits" << endl;
    }
}
