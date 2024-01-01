#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int mx,mn,ans=0;
    cin>>a[0];
    mx=a[0];
    mn=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        if (a[i]>mx)
        {
            ans++;
            mx=a[i];
        }
        if (a[i]<mn){
            ans++;
            mn=a[i];
        }
    }
    cout<<ans;
    return 0;
}