#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    bool flag=true;
    int ele;
    cin>>ele;
    for (int i=0;i<n;i++){
        if(ele==a[i]){
           cout<<"Element is present in array."<<endl;
           flag=false;
           break; 
        }
    }
    if(flag)
    cout<<"Element is not present in array."<<endl;
    
}