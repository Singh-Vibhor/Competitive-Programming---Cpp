#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        long long int a[n];
        cin>>a[0];
        int ans=0;
        if (a[0]!=0) ans++;
        for(int i=1;i<n;i++){
            cin>>a[i];
            if (a[i-1]==0 && a[i]!=0)
                ans++;
            if (ans>2)
                ans--;
        }
        cout<<ans<<endl;
    }
    return 0;
}