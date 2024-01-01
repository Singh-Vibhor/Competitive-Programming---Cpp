#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int sm=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
    }
    double ans=(sm*1.00)/(n*1.00);
    cout<<ans;
    return 0;
}