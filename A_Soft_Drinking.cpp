#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    c=c*d;
    p=p/np;
    l=k*l/nl;
    int ans = min(p,l);
    ans=(int)(min(ans,c)/n);
    cout<<ans;
    return 0;
}