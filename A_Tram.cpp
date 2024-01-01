#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b,ans=0,sm=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        sm=sm+b-a;
        ans=max(ans,sm);
    }
    cout<<ans;
    return 0;
}