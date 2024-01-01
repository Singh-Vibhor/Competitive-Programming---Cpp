#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b,a1=0,b1=0;

    for(int i=0;i<n;i++){
        cin>>a>>b;
        if (a==1)
        a1++;
        if (b==1)
        b1++;
    }
    int ans=0;
    ans+=min(a1,n-a1);
    ans+=min(b1,n-b1);
    cout<<ans;
    return 0;
}