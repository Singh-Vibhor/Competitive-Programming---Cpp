#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int mx=0,mn=100000,i1,i2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if (a[i]>mx){
            mx=a[i];
            i1=i;
        }
        if (a[i]<=mn){
            mn=a[i];
            i2=i;
        }
    }
    int ans=i1+n-1-i2;
    if(i2<i1)
    ans--;
    cout<<ans;
    return 0;
}