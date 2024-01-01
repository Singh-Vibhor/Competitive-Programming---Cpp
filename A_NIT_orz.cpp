#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--){
        int n,z;
        cin>>n>>z;
        int a[n];
        int mx=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if (z!=0){
                a[i]=a[i]|z;
            }
            if(a[i]>mx)
            mx=a[i]; 
        }
        cout<<mx<<endl;
    }
    return 0;
}